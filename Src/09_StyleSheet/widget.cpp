#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//颜色的三种表示方式:
	/**
	 * 1.rgb(0,220,235);
	 * 2.#9013fe
	 * 3.red
	 * 4.background = background-color
	 */
	ui->label->setStyleSheet("QLabel{color:rgb(0,220,235);"
		"background-color:#9013fe;}");
}

Widget::~Widget()
{
	delete ui;
}

