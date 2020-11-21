#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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
	 //因为QPixmap本身是绘图设备,不在窗口中绘图,则不需要在paintEvent事件中实现
	//创建绘图设备QPixmap并指定绘图设备的大小
	QPixmap pixmap(400, 300);
	//创建画家并指定绘图设备
	QPainter p(&pixmap);
	//把笑脸图画到QPixmap设备上(内存中)
	p.drawPixmap(0, 0, 80, 80, QPixmap(":/image/face.png"));
}

Widget::~Widget()
{
	delete ui;
}

