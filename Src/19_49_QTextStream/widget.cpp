#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__<< ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//调用写文件方法
	this->writeData();
	this->readData();
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

//QTextStream:读文件
void Widget::readData()
{
	//创建文件对象
	QFile file("./Demo.txt");
	//打开文件_只读方式
	bool isOpen = file.open(QIODevice::ReadOnly);
	//判断读取
	if (true == isOpen)
	{
		//创建流对象
		QTextStream textStream(&file);
		//前面以什么编码写后面以什么编码来读
		textStream.setCodec("UTF-8");
		QString str;
		int a;
		textStream >> str >> a;
		cout << str.toUtf8().data() << a;
		//[ d:\source\repos\qt\qtcode_vs\src\19_49_qtextstream\widget.cpp : 62 ] 主要看气质250 0
		//[注意]:不允许这样读取,读取有问题
	}
	//关闭文件
	file.close();
}
