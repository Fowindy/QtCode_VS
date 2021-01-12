#pragma once

#include <QThread>

class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject *parent);
	~MyThread();
protected:
	//QThread的虚函数_run线程处理函数_不能直接调用,通过start()间接调用
	void run();
signals:
	//定义处理完成信号
	void isDone();
};
