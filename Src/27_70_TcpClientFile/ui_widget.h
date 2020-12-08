/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditIP;
    QLineEdit *lineEditPort;
    QPushButton *btnConnect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 54, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 100, 81, 16));
        lineEditIP = new QLineEdit(Widget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(170, 70, 113, 20));
        lineEditPort = new QLineEdit(Widget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(190, 100, 113, 20));
        btnConnect = new QPushButton(Widget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(340, 90, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\347\232\204IP:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\347\232\204\347\253\257\345\217\243:", nullptr));
        lineEditIP->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        lineEditPort->setText(QCoreApplication::translate("Widget", "8888", nullptr));
        btnConnect->setText(QCoreApplication::translate("Widget", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
