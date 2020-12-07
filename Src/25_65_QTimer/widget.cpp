#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//初始化时实例化定时器对象_指定父对象释放内存
	timer = new QTimer(this);
}

Widget::~Widget()
{
	delete ui;
}
