#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//创建一个绘图设备,QImage::Format_ARGB32背景透明
	QImage image(400, 300, QImage::Format_ARGB32);
	QPainter p;
	p.begin(&image);
	//绘图
	p.drawImage(0, 0, QImage(":/image/face.png"));
	p.end();
	//绘图设备保存图片
	image.save("./image/image.png");
}

Widget::~Widget()
{
	delete ui;
}

