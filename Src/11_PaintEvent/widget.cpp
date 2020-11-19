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
	//p.drawPixmap(0, 0, width(), height(), QPixmap("./image/AiLianShuo.jpg"));

	//第三种方式:使用rect:获取左上角坐标和宽度高度
	p.drawPixmap(rect(), QPixmap("./image/timg.jpg"));

	//画直线_横向直线y轴坐标不变
	p.drawLine(50, 50, 150, 50);
	p.end();
}

