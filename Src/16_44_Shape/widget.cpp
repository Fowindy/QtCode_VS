#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//setWindowFlags去widget窗口边框_Qt::FramelessWindowHint_加内联函数windowFlags
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//设定widget窗口背景透明_Qt::WA_TranslucentBackground
	setAttribute(Qt::WA_TranslucentBackground);	//透明背景将不是自身部分
}

Widget::~Widget()
{
	delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
	//定义画家对象
	QPainter painter(this);
	//画家画画
	painter.drawPixmap(0, 0, QPixmap(":/image/sunny.png"));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
	//判断鼠标左右按键_右键关闭程序_左键坐标转换
	if (event->button() == Qt::RightButton)
	{
		//右键关闭
		close();
	}
	else if (event->button() == Qt::LeftButton)
	{
		//左键坐标转换_求坐标差值
		//当前光标点-窗口左上角坐标
		point = event->globalPos();//619,397(当前光标点)
		point = this->frameGeometry().topLeft();//560,220(原始左上坐标)
		point = event->globalPos() - this->frameGeometry().topLeft();//59,177(固定偏移点)
		qDebug() << event->globalPos();
	}
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		point1 = event->globalPos();//新的光标点(880,560)
		move(event->globalPos() - point);//新的左上角(880,560) - (59,177) = (560,220) + [(880,560) - (619,397)] 
	}
}
