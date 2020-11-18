#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	//表示此样式对Widget中所有的QLabel类型适应_全局作用
	this->setStyleSheet("QLabel{color:rgb(0,220,235);"
		"background-color:#9013fe;}");

	//颜色的三种表示方式:
	/**
	 * 1.rgb(0,220,235);
	 * 2.#9013fe
	 * 3.red
	 * 4.background = background-color
	 */
	 //表示此样式仅对此label对象适应_局部作用
	ui->label->setStyleSheet("QLabel{color:rgb(0,0,0);"
		"background-color:red;}");

	/**
	 * 方箱模型(margin,border,padding,content)
	 * 1.空白(margin):位于边框外,默认透明;
	 * 2.边框(border):边框为部件提供了四周的框架;
	 * 3.填充(padding):填充在边框和内容区域之间提供了空白间隔;
	 * 4.内容(content):控件内容放置区
	 * 注意:对于一个平面部件,比如一个空白,边框和填充都是0像素的部件而言,这四个矩形完全重合;
	 */
}

Widget::~Widget()
{
	delete ui;
}

