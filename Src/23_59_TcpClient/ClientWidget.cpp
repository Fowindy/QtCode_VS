#pragma execution_character_set("utf-8")
#include "ClientWidget.h"
#include "ui_ClientWidget.h"

ClientWidget::ClientWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ClientWidget)
{
	ui->setupUi(this);
	//将通讯套接字指针置空,防止野指针
	tcpSocket = NULL;
	//为通讯套接字分配空间,指定父对象
	tcpSocket = new QTcpSocket(this);
}

ClientWidget::~ClientWidget()
{
	delete ui;
}
