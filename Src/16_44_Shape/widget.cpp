#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//setWindowFlags去widget窗口边框_Qt::FramelessWindowHint_加内联函数windowFlags
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//设定widget窗口背景透明_Qt::WA_TranslucentBackground
	setAttribute(Qt::WA_TranslucentBackground);
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
