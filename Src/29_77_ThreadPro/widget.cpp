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
}

Widget::~Widget()
{
	delete ui;
}
