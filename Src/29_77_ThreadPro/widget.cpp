#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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
	//连接信号和槽_发送者:myT_信号函数:mySignal_接受者:this_处理槽函数:dealSignal
	connect(myT, &MyThread::mySignal, this, &Widget::dealSignal);
	//打印主线程号
	qDebug() << "主线程号:" << QThread::currentThread();
	//主窗口信号startThread连接MyThread槽函数myTimeOut
	connect(this, &Widget::startThread, myT, &MyThread::myTimeOut);
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
	//不能直接调用线程处理函数_直接调用导致线程处理函数和主线程是在同一个线程
	//myT->myTimeOut();

	//只能通过signal-slot的方式调用
}

/************************************
*@Method:    dealSignal
*@Access:    public
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 15:20
*@Describe:	 处理槽函数_实现
*************************************/
void Widget::dealSignal()
{
	//一秒数值加1
	static int i = 0;
	i++;
	ui->lcdNumber->display(i);
}

/************************************
*@Method:    startThread
*@Access:    private
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 15:45
*@Describe:	 开启子线程信号函数_实现
*************************************/
void Widget::startThread()
{

}
