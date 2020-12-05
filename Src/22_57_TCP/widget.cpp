#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//因为用指针初始化时动态分配空间
	tcpServer = new QTcpServer(this);//指定父对象,自动回收内存空间,不指定也可以

	//*监听
	//*QHostAddress::Any---绑定当前网卡所有ip(默认值)
	tcpServer->listen(QHostAddress::Any, 8888);//指定端口:8888(默认值为:0)
	//[qt4方式]_有连接产生newConnection信号
	connect(tcpServer, SIGNAL(QTcpServer::newConnection()), this, SLOT(sendMessage()));
	//[qt5方式]_有连接产生newConnection信号_需要Config:C++11_[]相当于返回值()是2号参数的参数
	connect(tcpServer, &QTcpServer::newConnection,
		[=]()
	{
		//取出建立好连接的套接字_取出的是指针不需要分配内存空间_nextPendingConnection_只会取队列中当前最近一个
		tcpSocket = tcpServer->nextPendingConnection();
		//peerAddress获取对方的ip并转字符类型
		QString ip = tcpSocket->peerAddress().toString();
		//peerPort获取对方的port(qint16类型)
		qint16 port = tcpSocket->peerPort();
		//拼接成可以显示的字符串
		QString temp = QString("[%1:%2]:连接成功!").arg(ip).arg(port);
	}
	);
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    sendMessage
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 11:28
*@Describe:	 [qt4方式]_发信息
*************************************/
void Widget::sendMessage()
{
	//取出建立好连接的套接字
	tcpSocket = tcpServer->nextPendingConnection();
}
