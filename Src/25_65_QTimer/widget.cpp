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
		//每次触发自增
		num++;
		//将自增的内容显示到定时器中
		ui->lcdNumber->display(num);
	});
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    on_btnClose_clicked
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 9:50
*@Describe:	 定时器关闭按钮
*************************************/
void Widget::on_btnClose_clicked()
{
	//>stop(停止定时器
	timer->stop();
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
