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

#pragma region QBuffer第二种写入方式_推荐
	//创建内存文件对象
	QBuffer buffer;
	//文件打开方式_只写
	bool isOpen = buffer.open(QIODevice::WriteOnly);
	//判断是否打开
	if (true == isOpen)
	{
		//创建数据流对象并绑定文件
		QDataStream dataStream(&buffer);
		//数据流写入内容
		dataStream << QString("测试") << 250;
		//关闭文件
		buffer.close();
		//打印内存对象内容
		qDebug() << buffer.buffer();
		//\x00\x00\x00\x04mK\x8B\xD5\x00\x00\x00\xFA
	}
#pragma endregion

#pragma region QBuffer第二种读取方式_推荐
	//文件打开方式_只读
	buffer.open(QIODevice::ReadOnly);
	//创建数据流读取对象
	QDataStream dataStreamIn;
	dataStreamIn.setDevice(&buffer);
	QString str;
	int a;
	dataStreamIn >> str >> a;
	//关闭文件
	buffer.close();
	//打印读取的内容
	qDebug() << str.toUtf8().data() << a;
	//测试 250
#pragma endregion

}

Widget::~Widget()
{
	delete ui;
}
