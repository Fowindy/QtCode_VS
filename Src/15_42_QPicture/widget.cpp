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
	//画好后保存
	picture.save("./image/picture.png");
}

Widget::~Widget()
{
	delete ui;
}

