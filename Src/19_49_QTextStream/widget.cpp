#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

//QTextStream:写文件
void Widget::writeData()
{
	//创建文件对象
	QFile file("./Demo.txt");
	//打开文件_只写方式
	bool isOpen = file.open(QIODevice::WriteOnly);
	//判断读取
	if (true == isOpen)	//[技巧]:判断的时候true放在前面可以防止赋值误操作
	{
	}
	//创建流对象
	QTextStream textStream(&file);
}
