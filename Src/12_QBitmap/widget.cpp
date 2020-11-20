#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

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

void Widget::paintEvent(QPaintEvent *)
{
	//定义画家对象
	QPainter p(this);
	//QPixmap_图片背景透明_彩色
	p.drawPixmap(0, 0, QPixmap("../image/butterfly_tm.png"));
	//QBitmap_图片背景透明_黑白
	p.drawPixmap(200, 0, QBitmap("../image/butterfly_tm.png"));
}

