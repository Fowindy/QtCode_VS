#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//动态分配空间,不能指定父对象
	myT = new MyThread;
	//子线程分配空间_可以指定父对象
	thread = new QThread(this);
	//把自定义线程加入到子线程中
	myT->moveToThread(thread);
}

Widget::~Widget()
{
	delete ui;
}
