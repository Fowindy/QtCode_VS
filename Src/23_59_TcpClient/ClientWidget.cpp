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
}

ClientWidget::~ClientWidget()
{
	delete ui;
}
