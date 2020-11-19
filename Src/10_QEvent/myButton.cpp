#pragma execution_character_set("utf-8")
#include "myButton.h"
#include <QMouseEvent>
#include <QDebug>

myButton::myButton(QWidget *parent)
	: QPushButton(parent)
{
}

myButton::~myButton()
{
}

void myButton::mousePressEvent(QMouseEvent *e)
{
	//判断是否为鼠标左键按下
	if (e->button() == Qt::LeftButton)
	{
		//事件的接收,接收后就会往下传递
		qDebug() << "鼠标左键按下";

		e->ignore();//忽略,事件继续往下传递,给谁传递?
					//事件传递给了父组件(Widget),不是给父类(QPushButton)
	}
	else
	{
		//不做处理
		//事件的忽略,忽略后事件继续传递
		QPushButton::mousePressEvent(e);
	}
}
