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
	tcpSocket = new QTcpSocket();

	//*监听
	//*QHostAddress::Any---绑定当前网卡所有ip(默认值)
	tcpServer->listen(QHostAddress::Any, 8888);//指定端口:8888(默认值为:0)
	//[qt4方式]_有连接产生newConnection信号
	connect(tcpServer, SIGNAL(QTcpServer::newConnection()), this, SLOT(sendMessage()));
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
