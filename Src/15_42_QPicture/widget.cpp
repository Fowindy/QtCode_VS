#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//1.先创建画家对象
	QPainter painter;
	//2.创建画具对象
	QPicture picture;
}

Widget::~Widget()
{
	delete ui;
}

