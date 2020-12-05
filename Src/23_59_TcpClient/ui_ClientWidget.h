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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *btnSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QTextEdit *textEditWrite;
    QTextEdit *textEditRead;
    QPushButton *btnConnect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(800, 600);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 1);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        btnSend = new QPushButton(ClientWidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));

        gridLayout->addWidget(btnSend, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(617, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 2);

        btnClose = new QPushButton(ClientWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 4, 3, 1, 1);

        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 3, 0, 1, 4);

        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));

        gridLayout->addWidget(textEditRead, 2, 0, 1, 4);

        btnConnect = new QPushButton(ClientWidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        gridLayout->addWidget(btnConnect, 1, 3, 1, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        lineEditIP->setText(QCoreApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", nullptr));
        lineEditPort->setText(QCoreApplication::translate("ClientWidget", "8888", nullptr));
        btnSend->setText(QCoreApplication::translate("ClientWidget", "\345\217\221\351\200\201", nullptr));
        btnClose->setText(QCoreApplication::translate("ClientWidget", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        btnConnect->setText(QCoreApplication::translate("ClientWidget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
