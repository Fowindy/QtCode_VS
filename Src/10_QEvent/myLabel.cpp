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
	int i = ev->x();
	int j = ev->y();
	/**
	 * 最终显示需要把整型转换为字符串_Qt格式化字符串说明
	 * QString str = QString("abc %1 ^_^ %2").arg(123).arg("mike");
	 * str = abc 123 ^_^ mike
	 */

	 //Qt格式化字符串_加嵌套css样式
	QString text = QString("<center><h1>Mouse Press Coordinate: (%1,%2)</h1></center>")
		.arg(i).arg(j);
	//显示,目前无法显示,因为自定义myLabel没有和ui绑定(提升)
	this->setText(text);
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{

}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{

}
