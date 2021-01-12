#pragma once

#include <QObject>

class MyThread : public QObject
{
	Q_OBJECT	//使用信号和槽头文件必须有Q_OBJECT宏

public:
	MyThread(QObject *parent);
	~MyThread();
	//线程处理函数myTimeOut_定义
	void myTimeOut();
signals:
	//信号函数_定义
	void mySignal();
};
