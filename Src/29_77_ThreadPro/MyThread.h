#pragma once

#include <QObject>

class MyThread : public QObject
{
	Q_OBJECT

public:
	MyThread(QObject *parent);
	~MyThread();
};
