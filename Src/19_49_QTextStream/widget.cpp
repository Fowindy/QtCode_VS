﻿#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//调用写文件方法
	this->writeData();
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
		//创建流对象
		QTextStream textStream(&file);
		//指定编码格式_UTF-8
		textStream.setCodec("UTF-8");
		//写入内容_默认以电脑平台编码格式
		textStream << QString("主要看气质") << 250;	//[犯错]:一定要QString()包含内容,不然乱码
		//关闭文件对象,释放资源
		file.close();
	}
}
