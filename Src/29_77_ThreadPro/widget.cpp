#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//子线程动态分配空间,不能指定父对象
	myT = new MyThread;
	//主线程分配空间_可以指定父对象
	thread = new QThread(this);
	//把自定义线程加入到子线程中
	myT->moveToThread(thread);
	//连接信号和槽_发送者:myT_信号函数:mySignal_接受者:this_处理槽函数:dealSignal
	connect(myT, &MyThread::mySignal, this, &Widget::dealSignal);
	//打印主线程号
	qDebug() << "主线程号:" << QThread::currentThread();
	//主窗口信号startThread连接MyThread槽函数myTimeOut
	connect(this, &Widget::startThread, myT, &MyThread::myTimeOut);
	//关闭X摧毁线程
	connect(this, &Widget::destroyed, this, &Widget::dealClose);
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
	//如线程已启动开始按钮直接返回
	if (thread->isRunning() == true)
	{
		return;
	}
	//开始按钮切换停止标志为false
	myT->setFlag(false);
	//启动线程,但是没有启动线程处理函数
	thread->start();
	//不能直接调用线程处理函数_直接调用导致线程处理函数和主线程是在同一个线程
	//myT->myTimeOut();

	//只能通过signal-slot的方式调用
	//向子线程发射启动信号
	emit startThread();
}

/************************************
*@Method:    on_btnStop_clicked
*@Access:    private
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 16:06
*@Describe:	 停止按钮槽函数_实现
*************************************/
void Widget::on_btnStop_clicked()
{
	//如线程已停止停止按钮直接返回
	if (thread->isRunning() == false)
	{
		return;
	}
	//停止按钮切换停止标志为true
	myT->setFlag(true);
	//主线程退出
	thread->quit();
	//主线程等待退出
	thread->wait();
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
*@Method:    dealClose
*@Access:    private
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 16:33
*@Describe:	 处理关闭槽函数_实现
*************************************/
void Widget::dealClose()
{
	//先调用关闭线程按钮槽函数
	on_btnStop_clicked();
}
