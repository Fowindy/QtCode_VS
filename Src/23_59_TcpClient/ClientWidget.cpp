#pragma execution_character_set("utf-8")
#include "ClientWidget.h"
#include "ui_ClientWidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ClientWidget)
{
	ui->setupUi(this);
	//将通讯套接字指针置空,防止野指针
	tcpSocket = NULL;
	//为通讯套接字分配空间,指定父对象
	tcpSocket = new QTcpSocket(this);
	//客户端连接信息对接服务端
	connect(tcpSocket, &QTcpSocket::connected,
		[=]()
	{
		//显示与服务器连接成功
		ui->textEditRead->setText(QString("与服务器:[%1:%2]连接成功!").arg(ui->lineEditIP->text()).arg(ui->lineEditPort->text()));
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
	tcpSocket->write(str.toUtf8().data());
}
