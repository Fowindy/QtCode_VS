﻿#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//初始化时tcpSocket置空,防止野指针异常
	tcpSocket = NULL;
	//初始化时tcpServer置空,防止野指针异常
	tcpServer = NULL;
	//因为用指针初始化时动态分配空间
	tcpServer = new QTcpServer(this);//指定父对象,自动回收内存空间,不指定也可以
	//setWindowTitle设置服务器窗口的名字
	setWindowTitle("服务端:8888");
	//*监听
	//*QHostAddress::Any---绑定当前网卡所有ip(默认值)
	tcpServer->listen(QHostAddress::Any, 8888);//指定端口:8888(默认值为:0)
	//[qt4方式]_有连接产生newConnection信号
	//connect(tcpServer, SIGNAL(QTcpServer::newConnection()), this, SLOT(sendMessage()));
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
		QString temp = QString("客户端[%1:%2]:连接成功!").arg(ip).arg(port);
		//并将字符串放到ui接收信息控件显示
		ui->textEditRead->setText(temp);
		//接收客户端信息_因tcpSocket待取出分配空间后使用
		connect(tcpSocket, &QTcpSocket::readyRead,
			[=]()
		{
			//tcpSocket->readAll()读取QByteArray数据
			QByteArray array = tcpSocket->readAll();
			//接收界面追加显示客户端信息
			ui->textEditRead->append(QString("客户端[%1]:").arg(port) + array);
		}
		);
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
//void Widget::sendMessage()
//{
//	//取出建立好连接的套接字
//	tcpSocket = tcpServer->nextPendingConnection();
//}

/************************************
*@Method:    on_btnSend_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 11:54
*@Describe:	 发送信息按钮事件
*************************************/
void Widget::on_btnSend_clicked()
{
	//判断tcpSocket或tcpServer为空则返回
	if (NULL == tcpSocket || NULL == tcpServer)
	{
		return;
	}
	//toPlainText获取编辑区内容
	QString str = ui->textEditWrite->toPlainText();
	//tcpSocket->write给对方发送数据
	//str.toUtf8().data()_字符串转QByteArray
	qint16 x = tcpSocket->write(str.toUtf8().data());
	//发送的数据也显示在读取界面_模拟聊天
	//客户端断开连接提示
	if (x == -1)
	{
		ui->textEditRead->append(QString("客户端[%1]:已离线!请重新尝试连接!!!").arg(tcpSocket->peerPort()));
	}
	else
	{
		//未输入消息不显示自己消息标头
		if (!str.isEmpty())
		{
			ui->textEditRead->append(QString("服务端[%1](自己):").arg(tcpSocket->localPort()) + str);
		}
		//发送后清空写入窗口
		ui->textEditWrite->clear();
	}
}

/************************************
*@Method:    on_btnClose_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 12:18
*@Describe:	 关闭服务端
*************************************/
void Widget::on_btnClose_clicked()
{
	//判断tcpSocket为空则返回
	if (NULL == tcpSocket || NULL == tcpServer)
	{
		return;
	}
	//disconnectFromHost主动与客户端断开连接
	tcpSocket->disconnectFromHost();
	//关闭服务端
	tcpSocket->close();
	//关闭服务器后tcpSocket和tcpServer置空
	tcpSocket = NULL;
	//解决客户端断开,服务端卡死的bug
	//tcpServer = NULL;
}
