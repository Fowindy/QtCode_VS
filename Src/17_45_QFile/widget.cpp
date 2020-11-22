#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QFile>	//文件
#include <QFileDialog>	//文件对话框
#include <QString>

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

void Widget::on_buttonRead_Clicked()
{
	//先获取文件路径
	QString path = QFileDialog::getOpenFileName(this, "open", "./", "文本文件(*.txt)");
	//判断路径是否为空
	if (path.isEmpty() == false)
	{
		//创建文件对象
		QFile file(path);
		//打开文件_只读_
		bool isOpen = file.open(QIODevice::ReadOnly);
		if (isOpen == true)
		{
			//一次性读完到字符数组
			QByteArray byteArray = file.readAll();
			//显示到编辑区
			//第一种方式:字节数组通过构造函数直接转换QString
			ui->textEdit->setText(QString(byteArray));
		}
	}
}
