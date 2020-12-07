﻿#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//监听套接字对象实例化
	tcpServer = new QTcpServer(this);

	//tcpServer->listen监听
	tcpServer->listen(QHostAddress::AnyIPv4, 8888);

	//setWindowTitle设置服务器窗口标题提示
	setWindowTitle("服务器端口为:8888");

	//最开始两个按钮都不能按变灰setEnabled
	ui->btnSelectFile->setEnabled(false);
	ui->btnSendFile->setEnabled(false);

	//connect如果客户端成功和服务器连接tcpServer会自动触发newconnection()信号
	connect(tcpServer, &QTcpServer::newConnection,
		[=]() {
		//取出建立好连接的套接字_tcpServer->nextPendingConnection
		tcpSocket = tcpServer->nextPendingConnection();

		//获取对方的ip和端口_tcpSocket->peerAddress_tcpSocket->peerPort
		QString ip = tcpSocket->peerAddress().toString();
		quint16 port = tcpSocket->peerPort();

		//拼接提示字符串
		QString str = QString("[%1:%2] 连接服务器成功!").arg(ip).arg(port);

		//显示到界面编辑区
		ui->textEdit->setText(str);

		//成功连接后才可以按选择按钮setEnabled
		ui->btnSelectFile->setEnabled(true);
	});
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    on_btnSelectFile_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 11:15
*@Describe:	 选择文件按钮事件
*************************************/
void Widget::on_btnSelectFile_clicked()
{
	//选择文件对话框获取文件全路径
	QString filePath = QFileDialog::getSaveFileName(this, "Open", "../");
}
