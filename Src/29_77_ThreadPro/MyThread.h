#pragma once

#include <QObject>

class MyThread : public QObject
{
	Q_OBJECT	//使用信号和槽头文件必须有Q_OBJECT宏

public:
	explicit MyThread(QObject *parent = 0);
	~MyThread();
	//线程处理函数myTimeOut_定义
	void myTimeOut();
signals:
	//信号函数_定义
	void mySignal();
private:
	bool isStop;	//定义子线程是否停止标志位_私有
};
