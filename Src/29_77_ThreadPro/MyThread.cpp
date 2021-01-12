﻿#include "MyThread.h"
#include "QThread"

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
	}
}
