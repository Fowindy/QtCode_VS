#include "MyThread.h"
#include "QThread"
#include <QDebug>

MyThread::MyThread(QObject *parent)
	: QObject(parent)
{
}

MyThread::~MyThread()
{
}

/************************************
*@Method:    myTimeOut
*@Access:    public
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 14:44
*@Describe:	 线程处理函数myTimeOut_实现
*************************************/
void MyThread::myTimeOut()
{
	while (1)
	{
		//线程触发时间间隔_1秒
		QThread::sleep(1);
		//每隔一秒发送一个信号
		emit mySignal();
		//打印子线程号
		qDebug() << "子线程号:" << QThread::currentThread();
	}
}
