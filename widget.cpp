#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog> // 引入檔案對話框

// 寫入檔案函式
// 修改後的寫入函式（支援 UTF-8 + 寫入 BOM 解決中文亂碼）
void Write(QString Filename, QString str)
{
    QFile mFile(Filename);
    if (!mFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "could not open file for write";
        return;
    }

    // 關鍵 1：先寫入 UTF-8 BOM (\xEF\xBB\xBF)，讓 Windows / Excel 自動辨別這是 UTF-8 中文
    mFile.write("\xEF\xBB\xBF");

    // 關鍵 2：將 QString 轉為 UTF-8 位元組寫入
    mFile.write(str.toUtf8());

    mFile.close();
}

// 修改後的讀取函式（正確以 UTF-8 解析並匯入）
void Read(QString Filename, QTableWidget *tableWidget)
{
    QFile mFile(Filename);
    if (!mFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "could not open file for read";
        return;
    }

    // 讀取整份檔案的 Raw Data 並轉成 UTF-8 字串
    QByteArray fileData = mFile.readAll();
    mFile.close();

    QString content = QString::fromUtf8(fileData);

    // 如果開頭有 UTF-8 BOM 標記 (0xFEFF)，將其濾除以免第一欄出現隱形亂碼
    if (content.startsWith(QChar(0xFEFF))) {
        content = content.mid(1);
    }

    // 依換行符號切割（同時處理 \n 與 \r\n）
    QStringList lines = content.split('\n');

    // 清空原本的表格資料（符合作業要求）
    tableWidget->setRowCount(0);

    for (QString line : lines) {
        line = line.trimmed();
        if (line.isEmpty()) continue; // 跳過空行

        QStringList fields = line.split(',');

        int rowCount = tableWidget->rowCount();
        tableWidget->insertRow(rowCount);

        for (int i = 0; i < fields.size() && i < tableWidget->columnCount(); ++i) {
            tableWidget->setItem(rowCount, i, new QTableWidgetItem(fields[i].trimmed()));
        }
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList ColTotle;
    ui->tableWidget->setColumnCount(4);
    ColTotle << QStringLiteral("學號")
             << QStringLiteral("班級")
             << QStringLiteral("姓名")
             << QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);

    // 確保啟動時表格中沒有資料（符合作業要求）
    ui->tableWidget->setRowCount(0);
}

Widget::~Widget()
{
    delete ui;
}

// 【新增資料按鈕】
void Widget::on_pushButton_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ui->lineEdit->text()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ui->lineEdit_2->text()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(ui->lineEdit_3->text()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(ui->lineEdit_4->text()));

    // 清空輸入框
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

// 【匯出按鈕】
void Widget::on_pushButton_2_clicked()
{
    // 讓使用者選擇或輸入儲存檔名（也可預設存到專案目錄的 data.csv）
    QString savePath = QFileDialog::getSaveFileName(this, "匯出 CSV", "test_data.csv", "CSV Files (*.csv)");
    if (savePath.isEmpty()) return;

    QString saveFile = "";

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        QStringList rowData;
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            rowData << (item ? item->text() : "");
        }
        saveFile += rowData.join(",") + "\n"; // 使用 join 可以避免行尾多出逗號
    }

    Write(savePath, saveFile);
}

// 【匯入按鈕】(你需要再介面上放一個 pushButton_3 作為「匯入」按鈕)
void Widget::on_pushButton_3_clicked()
{
    // 跳出檔案選擇視窗，選取專案中的 CSV 檔
    QString openPath = QFileDialog::getOpenFileName(this, "選擇匯入的 CSV 檔案", "", "CSV Files (*.csv)");
    if (openPath.isEmpty()) return;

    Read(openPath, ui->tableWidget);
}