#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//因为用指针初始化时动态分配空间
	tcpServer = new QTcpServer();
	tcpSocket = new QTcpSocket();
}

Widget::~Widget()
{
	delete ui;
}
