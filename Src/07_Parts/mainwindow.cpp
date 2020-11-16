#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//代码中重写按钮标题名和重写槽函数关闭为最大化
	ui->MyButton->setText("123");
	connect(ui->MyButton, &QPushButton::clicked, this, &MainWindow::showMaximized);
}

MainWindow::~MainWindow()
{
	delete ui;
}

