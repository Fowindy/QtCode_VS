﻿#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	myTimer = new QTimer(this);
	//只要定时器启动, 自动触发timeout()
	connect(myTimer, &QTimer::timeout, this, &Widget::dealTimeout);
	//在构造函数中为线程指针变量分配空间
	thread = new MyThread(this);
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    dealTimeout
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/09 16:28
*@Describe:	 定时器槽函数实现
*************************************/
void Widget::dealTimeout()
{
	static int i = 0;
	i++;
	//设置lcd的值显示
	ui->lcdNumber->display(i);
}

/************************************
*@Method:    on_btnStart_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/09 16:29
*@Describe:	 开始按钮
*************************************/
void Widget::on_btnStart_clicked()
{
	//如果定时器没有工作
	if (myTimer->isActive() == false)
	{
		//定时器启动_100ms
		myTimer->start(100);
	}

	//启动线程处理数据
	thread->start();
}
