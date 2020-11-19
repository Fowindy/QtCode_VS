#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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

void Widget::paintEvent(QPaintEvent *event)
{
	//第一种方法:直接构造方式
	//QPainter p(this);

	//第二种方式:调用begin和end函数方式
	QPainter p;	//创建画家对象
	p.begin(this);	//指定当前窗口为绘图设备
	//绘图操作
	//画背景图
	p.drawPixmap(0, 0, width(), height(), QPixmap("./image/AiLianShuo.jpg"));
	p.end();
}

