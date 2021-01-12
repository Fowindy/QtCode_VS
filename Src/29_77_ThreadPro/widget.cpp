#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//动态分配空间,不能指定父对象
	myT = new MyThread;
	//子线程分配空间_可以指定父对象
	thread = new QThread(this);
	//把自定义线程加入到子线程中
	myT->moveToThread(thread);
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    on_btnStart_clicked
*@Access:    public
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 15:16
*@Describe:	 开始按钮槽函数_实现
*************************************/
void Widget::on_btnStart_clicked()
{
	//启动线程,但是没有启动线程处理函数
	thread->start();
}
