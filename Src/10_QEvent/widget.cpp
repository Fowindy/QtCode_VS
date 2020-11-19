#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>


Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	sec1 = 0;
	sec2 = 0;
	ui->setupUi(this);
	timerId = this->startTimer(1000);	//以毫秒为单位	每一秒触发定时器
	this->timerId2 = this->startTimer(500);	//以毫秒为单位	每500毫秒触发定时器

	connect(ui->pushButton, &myButton::clicked,
		[=]()
	{
		qDebug() << "按钮被按下";
	});
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
	if (ev->timerId() == this->timerId)
	{
		TimerMethod(sec1, "Timer1", ev->timerId(), ui->label);
	}
	else if (ev->timerId() == this->timerId2)
	{
		TimerMethod(sec2, "Timer2", ev->timerId(), ui->label_2);
	}
}

void Widget::TimerMethod(int &sec, QString timerType, int timerId, myLabel* label)
{
	label->setText(QString("<center><h1>%2 out: %1</h1></center>")
		.arg(++sec)
		.arg(timerType)
	);
	if (timerId == this->timerId && sec == 25)
	{
		this->killTimer(timerId);
		label->setText(QString("<center><h1><font color=red>定时器%2关闭: %1</h1></center>")
			.arg(sec)
			.arg(timerType)
		);
	}
}

