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
	//connect连接timeout信号
	connect(timer, &QTimer::timeout,
		[=]()
	{
		//定义静态自增变量
		static int num = 0;
	});
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    on_btnStart_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 9:29
*@Describe:	 定时器开始按钮
*************************************/
void Widget::on_btnStart_clicked()
{
	//>start(启动定时器_时间间隔1000ms_每隔1000ms,定时器自动触发timeout信号
	timer->start(1000);
}
