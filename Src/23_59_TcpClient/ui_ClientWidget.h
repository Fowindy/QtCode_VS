/********************************************************************************
** Form generated from reading UI file 'ClientWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *btnSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(800, 600);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));

        gridLayout->addWidget(textEditRead, 0, 0, 1, 3);

        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 1, 0, 1, 3);

        btnSend = new QPushButton(ClientWidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));

        gridLayout->addWidget(btnSend, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(617, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        btnClose = new QPushButton(ClientWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 2, 2, 1, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "Widget", nullptr));
        btnSend->setText(QCoreApplication::translate("ClientWidget", "\345\217\221\351\200\201", nullptr));
        btnClose->setText(QCoreApplication::translate("ClientWidget", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
