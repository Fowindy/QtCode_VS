#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>

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

//QTextStream:写文件
void Widget::writeData()
{
}
