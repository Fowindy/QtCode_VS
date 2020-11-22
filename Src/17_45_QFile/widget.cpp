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

void Widget::on_buttonRead_clicked()
{
	//先获取文件路径
	QString path = QFileDialog::getOpenFileName(this, "open", "./File", "文本文件(*.txt)");
	//判断路径是否为空
	if (path.isEmpty() == false)
	{
		//创建文件对象
		QFile file(path);
		//打开文件_只读_
		bool isOpen = file.open(QIODevice::ReadOnly);
		if (isOpen == true)
		{
#pragma region 第一种读取方式:全部读取
			////一次性读完到字符数组_readAll默认为utf-8编码,其他乱码
			//QByteArray byteArray = file.readAll();
			////显示到编辑区
			////第一种方式:字节数组通过构造函数直接转换QString
			////ui->textEdit->setText(QString(byteArray));
			////第二种方式:字符数组自动转换QString
			//ui->textEdit->setText(byteArray);	//字符数组自动转换QString    
#pragma endregion

#pragma region 第二种读取方式:单行读取
			//定义字节数组
			QByteArray byteArray;
			//没有到文件尾则继续读取
			while (file.atEnd() == false)
			{
				//单行读取
				byteArray += file.readLine();
			}
			ui->textEdit->setText(byteArray);
#pragma endregion


		}
		//文件对象用完关闭资源
		file.close();
	}
}

void Widget::on_buttonWrite_clicked()
{
	//保存对话框获取保存路径
	QString path = QFileDialog::getSaveFileName(this, "save", "./File", "文本文档(*.txt)");
	//判断路径是否为空
	if (path.isEmpty() != true)
	{
		//创建文件对象
		QFile file;
		//文件对象关联文件
		file.setFileName(path);
		//打开文件,只写方式
		bool isOpen = file.open(QIODevice::WriteOnly);
		//打开成功
		if (isOpen == true)
		{
			//ui->textEdit->toPlainText()获取编辑区内容
			QString str = ui->textEdit->toPlainText();
			//写文件QString -> QByteArray 第一种:直接转UTF8
			//file.write(str.toUtf8());

			//[复习]---第二种:QString -> c++ string ->char *
			//file.write(str.toStdString().data());

			//[知识点:转换本地编码]---str.toLocal8Bit()
			file.write(str.toLocal8Bit());

			//[知识点:QString -> QByteArray]---第一种:转换中文
			QString buf = "123";
			QByteArray array = buf.toUtf8();	//中文
			//[知识点:QString -> QByteArray]---第二种:转换本地编码
			//array = buf.toLocal8Bit();	//本地编码

			//[知识点:QByteArray -> char*]---array.data()
			char *ch = array.data();
		}
		//使用完关闭资源
		file.close();
	}
}
