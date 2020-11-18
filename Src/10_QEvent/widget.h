﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();
protected:
	//键盘按下事件
	void keyPressEvent(QKeyEvent *);	//占位符参数，方便以后修改函数定义且不需要修改接口
	//计时器事件
	void timerEvent(QTimerEvent *);
private:
	Ui::Widget *ui;
	int timerId;	//定义定时器的Id
};
#endif // WIDGET_H
