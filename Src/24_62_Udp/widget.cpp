﻿#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//给套接字分配空间_指定父对象_回收空间_不指定也可以
	udpSocket = new QUdpSocket(this);
}

Widget::~Widget()
{
	delete ui;
}