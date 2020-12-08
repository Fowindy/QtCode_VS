#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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
		//取出接受的内容
		QByteArray buf = tcpSocket->readAll();
		//取出接收的内容_接收头和接收文件
		if (true == isStart)	//接收头
		{
			isStart = false;
			//解析头部信息	Qstring buf = "hel1o##1024"
			//QString str = "hello##1024#mike";
			//str.section("##", 0, 0);

			//初始化
			recvfileName = QString(buf).section("##", 0, 0);
			recvFileSize = QString(buf).section("##", 1, 1).toInt();
			recvSize = 0;

			//打开文件
			recvfile.setFileName(recvfileName);
			bool isOk = recvfile.open(QIODevice::WriteOnly);
			if (false == isOk)
			{
				qDebug() << "写入出错! 40";
			}
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
