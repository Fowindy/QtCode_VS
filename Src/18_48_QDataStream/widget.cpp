#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>	//以二进制的方式读写文件
#include <QFile>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	this->writeData();
}

Widget::~Widget()
{
	delete ui;
}

void Widget::writeData()
{
	//创建文件对象
	QFile file("./test.txt");

	//打开文件,只写方式打开
	bool isOpen = file.open(QIODevice::WriteOnly);

	if (isOpen)
	{
		//QDataStream(QIODevice *)-->QDataStream dataStream(&file)
		//继承关系:file <-- QFileDevice <-- QIODevice
		//注意:创建数据流和file文件关联
		//往数据流中写数据,相当于往文件里写数据
		QDataStream dataStream(&file);

		dataStream << QString("主要看气质") << 250;

		//关闭文件对象
		file.close();	//乱码:以二进制存储
	}
}

void Widget::readData()
{
	//创建文件对象
	QFile file("./test.txt");

	//打开方式,只读方式打开
	bool isOpen = file.open(QIODevice::ReadOnly);

	if (isOpen)
	{
		QDataStream dataStream(&file);
	}
}
