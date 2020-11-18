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
	this->startTimer(1000);	//以毫秒为单位	每一秒触发定时器
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

void Widget::timerEvent(QTimerEvent *ev)
{
	static int sec = 0;
	ui->label->setText(QString("<center><h1>timer out: %1</h1></center>").arg(sec++
	));
}

