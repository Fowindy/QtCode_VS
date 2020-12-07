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
	//初始化标识
	isStart = true;
	//接收连接
	connect(tcpSocket, &QTcpSocket::readyRead,
		[=]()
	{
		//取出接收的内容_接收头和接收文件
		if (true == isStart)	//接收头
		{
			isStart = false;
		}
		else	//接收文件信息
		{

		}
	}
	);
}

Widget::~Widget()
{
	delete ui;
}
