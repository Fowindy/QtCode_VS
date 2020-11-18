#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>

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

void Widget::keyPressEvent(QKeyEvent *ev)
{
	//显示键盘按键的ASCII码
	//qDebug() << ev->key();

	//键盘按键的ASCII码转换字符
	qDebug() << (char)ev->key();

	//特殊按键判断
	if (ev->key() == Qt::Key_Shift)
	{
		qDebug() << "Shift";
	}
}

