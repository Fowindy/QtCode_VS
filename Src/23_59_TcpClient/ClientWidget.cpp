﻿#pragma execution_character_set("utf-8")
#include "ClientWidget.h"
#include "ui_ClientWidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ClientWidget)
{
	ui->setupUi(this);
	//设置窗口名字:客户端
	setWindowTitle("客户端");
	//将通讯套接字指针置空,防止野指针
	tcpSocket = NULL;
	//为通讯套接字分配空间,指定父对象
	tcpSocket = new QTcpSocket(this);
	//客户端连接信息对接服务端
	connect(tcpSocket, &QTcpSocket::connected,
		[=]()
	{
		//显示与服务器连接成功
		ui->textEditRead->setText(QString("服务器[%1:%2]:连接成功!").arg(ui->lineEditIP->text()).arg(ui->lineEditPort->text()));
		connect(tcpSocket, &QTcpSocket::readyRead,
			[=]()
		{
			//读取所有客户端发来的消息
			QByteArray array = tcpSocket->readAll();
			QString str = array.data();
			//显示在读取界面
			//接收消息为空不显示
			if (!str.isEmpty())
			{
				ui->textEditRead->append(QString("服务端[%1]:").arg(ui->lineEditPort->text()) + str);
			}
		}
		);
	}
	);
}

ClientWidget::~ClientWidget()
{
	delete ui;
}

/************************************
*@Method:    on_btnConnect_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 13:21
*@Describe:	 连接按钮
*************************************/
void ClientWidget::on_btnConnect_clicked()
{
	//从用户输入框获取服务器的IP和Port
	QString ip = ui->lineEditIP->text();
	qint16 port = ui->lineEditPort->text().toInt();

	//connectToHost主动和服务器建立连接_此处需要将ip转QHostAddress
	tcpSocket->connectToHost(QHostAddress(ip), port);
}

/************************************
*@Method:    on_btnSend_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 14:18
*@Describe:	 发送按钮
*************************************/
void ClientWidget::on_btnSend_clicked()
{
	//toPlainText获取客户端输入的要发送的内容
	QString str = ui->textEditWrite->toPlainText();
	//发送数据
	qint16 x = tcpSocket->write(str.toUtf8().data());
	if (x == -1)
	{
		ui->textEditRead->append(QString("服务端[%1]:已离线!请重新尝试连接!!!").arg(ui->lineEditPort->text()));
	}
	else
	{
		//发送的数据也显示在读取界面_模拟聊天
		//未输入消息不显示自己消息标头
		if (!str.isEmpty())
		{
			ui->textEditRead->append(QString("客户端[%1](自己):").arg(tcpSocket->localPort()) + str);
		}
		//发送数据后清空写入窗口
		ui->textEditWrite->clear();
	}
}

/************************************
*@Method:    on_btnClose_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 18:55
*@Describe:	 断开连接按钮
*************************************/
void ClientWidget::on_btnClose_clicked()
{
	//disconnectFromHost断开tcpSocket连接
	tcpSocket->disconnectFromHost();
	//关闭tcpSocket连接
	tcpSocket->close();
}
