#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//创建字节数组
	QByteArray byteArray;
	//创建内存文件对象
	QBuffer memFile(&byteArray);
	memFile.open(QIODevice::WriteOnly);

	memFile.write("11111111\n");
	memFile.write("aaaaaaa");

	memFile.close();
	qDebug() << memFile.buffer();
	//11111111\naaaaaaa
	qDebug() << "array:" << byteArray;
	//array:11111111\naaaaaaa
}

Widget::~Widget()
{
	delete ui;
}
