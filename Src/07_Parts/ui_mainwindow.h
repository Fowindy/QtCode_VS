/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionbaocun;
    QWidget *centralwidget;
    QPushButton *MyButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *pushButton_5;
    QWidget *page_2;
    QToolButton *toolButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QCommandLinkButton *commandLinkButton;
    QWidget *page_5;
    QPushButton *pushButton_6;
    QWidget *page_4;
    QCheckBox *checkBox;
    QPushButton *change;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDateTimeEdit *dateTimeEdit;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QKeySequenceEdit *keySequenceEdit;
    QDial *dial;
    QLabel *labelText;
    QLabel *labelImage;
    QLabel *labelGif;
    QLabel *labelUrl;
    QLCDNumber *lcdNumber;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuEdit;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        actionbaocun = new QAction(MainWindow);
        actionbaocun->setObjectName(QString::fromUtf8("actionbaocun"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MyButton = new QPushButton(centralwidget);
        MyButton->setObjectName(QString::fromUtf8("MyButton"));
        MyButton->setGeometry(QRect(50, 120, 75, 23));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(250, 140, 161, 72));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 174, 70));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(500, 180, 69, 121));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 69, 69));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 10, 75, 23));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 69, 69));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 10, 37, 18));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 210, 127, 80));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(80, 350, 201, 80));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        commandLinkButton = new QCommandLinkButton(page_3);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(20, 40, 185, 41));
        stackedWidget->addWidget(page_3);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        pushButton_6 = new QPushButton(page_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 20, 75, 23));
        stackedWidget->addWidget(page_5);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        checkBox = new QCheckBox(page_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 40, 71, 16));
        stackedWidget->addWidget(page_4);
        change = new QPushButton(centralwidget);
        change->setObjectName(QString::fromUtf8("change"));
        change->setGeometry(QRect(10, 350, 75, 23));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 440, 69, 22));
        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(110, 440, 71, 22));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 440, 113, 20));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 480, 42, 22));
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(80, 480, 62, 22));
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(150, 480, 118, 22));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(280, 480, 150, 22));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(20, 510, 194, 22));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(310, 410, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(450, 240, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(220, 510, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(490, 390, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        keySequenceEdit = new QKeySequenceEdit(centralwidget);
        keySequenceEdit->setObjectName(QString::fromUtf8("keySequenceEdit"));
        keySequenceEdit->setGeometry(QRect(240, 530, 113, 20));
        dial = new QDial(centralwidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(190, 250, 50, 64));
        labelText = new QLabel(centralwidget);
        labelText->setObjectName(QString::fromUtf8("labelText"));
        labelText->setGeometry(QRect(20, 20, 71, 61));
        labelImage = new QLabel(centralwidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(150, 20, 71, 61));
        labelGif = new QLabel(centralwidget);
        labelGif->setObjectName(QString::fromUtf8("labelGif"));
        labelGif->setGeometry(QRect(260, 20, 171, 101));
        labelUrl = new QLabel(centralwidget);
        labelUrl->setObjectName(QString::fromUtf8("labelUrl"));
        labelUrl->setGeometry(QRect(470, 20, 101, 61));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(610, 10, 64, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionnew);
        menu->addSeparator();
        menu->addAction(actionbaocun);
        menu->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(MyButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionnew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        actionbaocun->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        MyButton->setText(QCoreApplication::translate("MainWindow", "button", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Page 1", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Page 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "CommandLinkButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        change->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "12345", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "abcde", nullptr));

        lineEdit->setText(QCoreApplication::translate("MainWindow", "\347\216\213\345\262\263", nullptr));
        labelText->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelGif->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelUrl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
