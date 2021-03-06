﻿#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

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

		connect(tcpSocket, &QTcpSocket::readyRead,
			[=]()
		{
			//取客户端的信息
			QByteArray buf = tcpSocket->readAll();
			if (QString(buf) == "file done")
			{//文件接收完毕
				ui->textEdit->append("文件发送完毕");
				file.close();

				//断开客户端端口
				tcpSocket->disconnectFromHost();
				tcpSocket->close();
			}
		}
		);
	});

	//连接定时器
	connect(&timer, &QTimer::timeout,
		[=]()
	{
		//发送文件时关闭定时器
		timer.stop();
		//发送文件
		sendData();
	}
	);
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    sendData
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 11:45
*@Describe:	 发送文件数据函数
*************************************/
void Widget::sendData()
{
	//定义一个文件大小变量并置0
	qint64 len = 0;
	do
	{
		ui->textEdit->append("正在发送文件……");
		//定义每次发送数据大小为4k的buf
		char buf[4 * 1024] = { 0 };
		//每次循环长度置0
		len = 0;
		//往文件中读数据
		len = file.read(buf, sizeof(buf));
		//发送数据_读多少发多少
		len = tcpSocket->write(buf, len);
		//已发送数据长度累加
		sendSize += len;
	} while (len > 0);	//如果发送数据大于0继续发送_或fileSize != sendSize

	//已发送文件大小等于文件总大小则发送完毕
	//if (sendSize == fileSize)
	//{
	//	ui->textEdit->append("文件发送完毕!");
	//	//发送完毕_完毕文件对象_把客户端端口断开_关闭客户端套接字对象
	//	file.close();
	//	tcpSocket->disconnectFromHost();
	//	tcpSocket->close();
	//}
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
	QString filePath = QFileDialog::getOpenFileName(this, "Open", "../");

	if (false == filePath.isEmpty())	//如果选择文件路径有效
	{
		//先清除一下文件名称,避免上次干扰
		fileName.clear();
		//重置文件大小
		fileSize = 0;
		//初始化已发送的大小为0
		sendSize = 0;
		//只读方式打开文件,获取文件大小和名称(全局变量)
		QFileInfo info(filePath);
		fileName = info.fileName();	//获取文件名字
		fileSize = info.size();	//获取文件大小

		//指定文件的名字
		file.setFileName(filePath);

		//打开文件
		bool isok = file.open(QIODevice::ReadOnly);

		if (false == isok)
		{
			qDebug() << "只读方式打开文件失败 77";
		}

		//显示打开文件路径
		ui->textEdit->append(filePath);

		//选择文件后按钮变灰
		ui->btnSelectFile->setEnabled(false);
		//选择文件后发送按钮变亮
		ui->btnSendFile->setEnabled(true);
	}
	else	//如果选择文件路径无效
	{
		qDebug() << "选择文件路径出错 62";
	}
}

/************************************
*@Method:    on_btnSendFile_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 11:35
*@Describe:	 发送文件按钮事件
*************************************/
void Widget::on_btnSendFile_clicked()
{
	ui->btnSendFile->setEnabled(false);
	//先发送文件头信息_文件名##文件大小
	QString head = QString("%1##%2").arg(fileName).arg(fileSize);
	//发送头部信息
	qint64 len = tcpSocket->write(head.toUtf8());

	//如果len大于0说明发送成功
	if (len > 0)
	{
		//_发送真正的文件信息
		//防止TCP黏包文件_需要通过定时器延时20 ms
		//发送文件的时候启动定时器,延时20ms
		timer.start(20);
	}
	else
	{
		//发送失败_提示_关闭文件对象_选择文件按钮置亮_发送按钮置灰
		qDebug() << "头部信息发送失败110";
		file.close();
		ui->btnSelectFile->setEnabled(true);
		ui->btnSendFile->setEnabled(false);
	}
}
