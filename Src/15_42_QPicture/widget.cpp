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
	//把画具给画家
	painter.begin(&picture);
	//画笑脸图片
	painter.drawPixmap(0, 0, 80, 80, QPixmap(":/image/face.png"));
	//画一条横向直线
	painter.drawLine(50, 50, 150, 50);
	painter.end();
	//画好后保存_二进制图片_外面不可查看
	picture.save("./picture.png");
}

Widget::~Widget()
{
	delete ui;
}

//************************************
// Method:    paintEvent
// Access:    protected 
// Returns:   void
// Author: 	  Fowindy
// Parameter: QPaintEvent *
// Created:   2020/11/22 21:51
//************************************
//paintEvent事件显示图片
void Widget::paintEvent(QPaintEvent *)
{
	//创建画家对象
	QPainter painter(this);
	//创建画具对象
	QPicture picture;
	//往画具中加载生成的二进制图片
	//[注意]---程序运行加载二进制图片(最好放在当前根目录,不然会导致Qt显示不全)
	picture.load("./picture.png");
	//画家在widget画出图片
	painter.drawPicture(0, 0, picture);
}

