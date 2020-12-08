#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//初始化时将进度条置0
	ui->progressBar->setValue(0);
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

				tcpSocket->disconnectFromHost();//断开连接
				tcpSocket->close();//关闭套接字
				return;//如果文件打开失败,中断函数
			}
			//弹出对话框,显示接收文件的信息
			QString str = QString("接收的文件:[%1:%2]").arg(recvfileName).arg(recvFileSize / 1024);
			QMessageBox::information(this, "文件信息", str);
		}
		else	//接收文件信息
		{
			//获取接收读取内容的长度并加到接收长度中
			qint64 len = recvfile.write(buf);
			recvSize += len;
			if (recvSize == recvFileSize)	//文件接收完成
			{
				//文件接收完成务必关闭文件对象
				recvfile.close();
				//弹出文件接收完成的对话框
				QMessageBox::information(this, "完成", "文件接收完成!");
				//文件接收完成关闭套接字和对象
				tcpSocket->disconnectFromHost();
				tcpSocket->close();
			}
		}
	}
	);
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    on_btnConnect_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/09 0:11
*@Describe:	 连接按钮
*************************************/
void Widget::on_btnConnect_clicked()
{
	//获取服务器的ip和端口
	QString ip = ui->lineEditIP->text();
	quint16 port = ui->lineEditPort->text().toInt();

	//连接服务器
	tcpSocket->connectToHost(QHostAddress(ip), port);
}
