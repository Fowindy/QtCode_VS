#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//代码中重写按钮标题名和重写槽函数关闭为最大化
	ui->MyButton->setText("123");
	connect(ui->MyButton, &QPushButton::clicked, this, &MainWindow::showMaximized);

	//QLineEdit控件
	//获取内容
	QString str = ui->lineEdit->text();
	qDebug() << str;
	//设置内容
	ui->lineEdit->setText("Fowindy");
	//设置内容显示间隙
	ui->lineEdit->setTextMargins(15, 10, 0, 0);
	//设置密码显示模式(黑点)
	ui->lineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_change_clicked()
{
	static int i = 0;	//静态的,每次不释放这个值,实现切换
	ui->stackedWidget->setCurrentIndex(++i % 3);
}

