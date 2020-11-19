#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>


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

void Widget::TimerMethod(int &sec, QString timerType, int timerId, QLabel* label)
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

void Widget::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "父组件接收到myButton的事件传递";
}

void Widget::closeEvent(QCloseEvent *event)
{
	//弹出QMessageBox来提示用户选择
	int result = QMessageBox::question(this, "关闭窗口", "确定关闭窗口?", "确定", "取消");
	if (result == 0)
	{
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

//bool Widget::event(QEvent *e)
//{
//	//事件分发
//	switch (e->type())
//	{
//	case QEvent::MouseButtonPress:
//		//使用dynamic_cast将父类转成子类(比static_cast有检查,更安全)
//		mousePressEvent(dynamic_cast<QMouseEvent*>(e));
//		break;
//	case QEvent::Close:
//		closeEvent(dynamic_cast<QCloseEvent*>(e));
//		break;
//		/**
//		 * ......
//		 */
//	}
//	return false;
//}

