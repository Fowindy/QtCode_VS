#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//实例化通信套接字对象
	tcpSocket = new QTcpSocket(this);
}

Widget::~Widget()
{
	delete ui;
}
