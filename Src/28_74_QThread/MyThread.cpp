#include "MyThread.h"

MyThread::MyThread(QObject *parent)
	: QThread(parent)
{
}

MyThread::~MyThread()
{
}

/************************************
*@Method:    run
*@Access:    protected
*@Returns:   void
*@Author: 	 Fowindy
*@Created:   2021/01/12 11:01
*@Describe:	 run线程处理函数
*************************************/
void MyThread::run()
{
	//throw std::logic_error("The method or operation is not implemented.");
	//很复杂的数据处理需要耗时5秒
	//sleep:秒_msleep:毫秒_usleep:微秒
	sleep(5);
	//处理完成发射信号
	emit isDone();
}
