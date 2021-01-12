#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MyThread.h"	//必须包含MyThread头文件

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();

private:
	Ui::Widget *ui;
	MyThread *myT;	//定义线程函数指针变量
};
#endif // WIDGET_H
