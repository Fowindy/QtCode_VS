#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>	//定时器头文件
#include "MyThread.h"	//在widget.h文件中包含MyThread.h头文件

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
	QTimer *myTimer;	//声明定时器变量
	MyThread *thread;	//创建线程对象指针变量
private slots:
	void dealTimeout();	//定时器槽函数
	void on_btnStart_clicked();	//开始按钮触发槽函数
	void dealDone();	//定义线程结束槽函数
	void stopThread();	//停止线程槽函数_定义
};
#endif // WIDGET_H
