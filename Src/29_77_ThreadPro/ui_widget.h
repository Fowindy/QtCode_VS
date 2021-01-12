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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcdNumber;
    QPushButton *btnStart;
    QPushButton *btnStop;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->setEnabled(true);
        Widget->resize(406, 366);
        Widget->setTabletTracking(false);
        Widget->setFocusPolicy(Qt::NoFocus);
        Widget->setContextMenuPolicy(Qt::DefaultContextMenu);
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(70, 80, 241, 111));
        btnStart = new QPushButton(Widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(70, 210, 75, 23));
        btnStop = new QPushButton(Widget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(240, 210, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnStart->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        btnStop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
