﻿#pragma once

#include <QLabel>

class myLabel : public QLabel
{
	Q_OBJECT

public:
	myLabel(QWidget *parent);
	~myLabel();
protected:
	//子类头文件重写父类虚函数(声明)_鼠标按下
	void mousePressEvent(QMouseEvent *ev);
	//子类头文件重写父类虚函数(声明)_鼠标释放
	void mouseReleaseEvent(QMouseEvent *ev);
signals:
public slots:
};
