/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 30, 771, 291));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(61, 370, 721, 21));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 370, 36, 16));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(61, 410, 721, 21));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 410, 36, 16));
        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(61, 450, 721, 21));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 450, 36, 16));
        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(61, 490, 721, 21));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 490, 36, 16));
        splitter = new QSplitter(Widget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 550, 761, 18));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName("pushButton");
        splitter->addWidget(pushButton);
        pushButton_3 = new QPushButton(splitter);
        pushButton_3->setObjectName("pushButton_3");
        splitter->addWidget(pushButton_3);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName("pushButton_2");
        splitter->addWidget(pushButton_2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\255\270\350\231\237\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\217\255\347\264\232\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\351\233\273\350\251\261\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\226\260\345\242\236", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\214\257\345\205\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\214\257\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
