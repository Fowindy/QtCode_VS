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
}

Widget::~Widget()
{
	delete ui;
}
