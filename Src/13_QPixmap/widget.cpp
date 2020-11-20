#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	/**
	 * 绘图设备的区别:
	 * QPixmap:针对屏幕进行了优化,和平台相关,不能对图片像素点进行修改
	 * QImage:和平台无关,可以对图片进行像素点修改,可以实现在线程中绘图(比如导航的实时刷新)
	 * QPicture:保存绘图的状态(二进制文件)
	 */
}

Widget::~Widget()
{
	delete ui;
}

