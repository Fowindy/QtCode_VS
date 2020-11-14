#include "MyButton.h"
#include <QDebug>	//使用QDebug打印一句话
#pragma execution_character_set("utf-8")
MyButton::MyButton(QWidget *parent)
	: QPushButton(parent)	//通过参数列表的方式给基类传参
{
}

MyButton::~MyButton()
{
	qDebug() << "按钮被析构";
}
