#include "myLabel.h"
//包含鼠标事件头文件
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent)
	: QLabel(parent)
{
}

myLabel::~myLabel()
{
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
	MyMethod(ev);
}

void myLabel::MyMethod(QMouseEvent * ev)
{
	QString buttonName;
	switch (ev->type())
	{
	case QEvent::MouseButtonPress:
		buttonName = "MouseButtonPress";
		break;
	case QEvent::MouseButtonRelease:
		buttonName = "MouseButtonRelease";
		break;
	case QEvent::MouseMove:
		buttonName = "MouseMove";
		break;
	}
	int i = ev->x();
	int j = ev->y();
	/**
	 * 最终显示需要把整型转换为字符串_Qt格式化字符串说明
	 * QString str = QString("abc %1 ^_^ %2").arg(123).arg("mike");
	 * str = abc 123 ^_^ mike
	 */
	QString buttonInfo;
	if (ev->button() == Qt::LeftButton)	//鼠标左键按下
	{
		buttonInfo = "LeftButton";
	}
	else if (ev->button() == Qt::RightButton)	//鼠标右键按下
	{
		buttonInfo = "RightButton";
	}
	else if (ev->button() == Qt::MidButton)	//鼠标滚轮按下
	{
		buttonInfo = "MidButton";
	}
	//Qt格式化字符串_加嵌套css样式
	QString text = QString("<center><h1>Mouse %1 %4 Coordinate: (%2,%3)</h1></center>")
		.arg(buttonInfo).arg(i).arg(j).arg(buttonName);
	//显示,目前无法显示,因为自定义myLabel没有和ui绑定(提升)
	this->setText(text);
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
	MyMethod(ev);
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
	MyMethod(ev);
}
