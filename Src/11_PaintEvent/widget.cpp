#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>

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

	//定义画笔
	QPen pen;
	//设置线宽
	pen.setWidth(5);
	//设置颜色_通过枚举_局限性
	//pen.setColor(Qt::red);

	//设置颜色_通过rgb
	pen.setColor(QColor(160, 41, 192));

	//设置风格_虚线
	pen.setStyle(Qt::DotLine);

	//把画笔交给画家
	p.setPen(pen);

	//画直线_横向直线y轴坐标不变
	p.drawLine(50, 50, 150, 50);
	//画直线_竖向直线x轴坐标不变
	p.drawLine(50, 50, 50, 150);

	//画矩形_起点坐标+宽+高
	p.drawRect(150, 150, 100, 50);

	//画圆形_圆心+宽半径+高半径
	p.drawEllipse(QPoint(150, 150), 100, 50);
	p.end();
}

