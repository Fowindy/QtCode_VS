#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MyThread.h"	//必须包含MyThread头文件
#include <QThread>		//自带线程头文件

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
	QThread *thread;	//自带子线程指针变量
public slots:
	//开始按钮槽函数_定义
	void on_btnStart_clicked();
	//处理槽函数_定义
	void dealSignal();
};
#endif // WIDGET_H
