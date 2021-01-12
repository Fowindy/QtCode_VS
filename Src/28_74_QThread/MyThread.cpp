#include "MyThread.h"

MyThread::MyThread(QObject *parent)
	: QThread(parent)
{
}

MyThread::~MyThread()
{
}

void MyThread::run()
{
	throw std::logic_error("The method or operation is not implemented.");
}
