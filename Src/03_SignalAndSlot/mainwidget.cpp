#include "mainwidget.h"
#include <QDebug>   //打印
#pragma execution_character_set("utf-8")

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	//固定父窗口大小
	resize(400, 300);
	b.setParent(this);
	b.setText("关闭");
	b.move(100, 100);

	//b1为指针,需要动态分配空间
	b1 = new QPushButton(this);
	b1->setText("ABC");

	//    connect(&b,&QPushButton::pressed,this,&MainWidget::close);
		/*
		 * &b:信号发出者,指针类型
		 * &QPushButton::pressed:处理信号   &发送者的类名::信号名字
		 * this:信号接收者
		 * &MainWidget::close:槽函数,信号处理函数    &接收者的类名::槽函数名字
	*/

	/*
	 * 自定义槽函数,普通函数的用法
	 * Qt5:槽函数可以是任意的成员函数,普通全局函数,静态函数
	 * 槽函数需要和信号一致(参数,返回值)
	 * 由于信号都是没有返回值的,所以,槽函数一定没有返回值
	 *
*/
//案例1:自定义一个槽函数,松开b按钮改变按钮显示的标题
	connect(&b, &QPushButton::released, this, &MainWidget::ChangeBtnTitile);

	//案例2:实现松开b1按钮隐藏b按钮
	connect(b1, &QPushButton::released, &b, &QPushButton::hide);

	//案例3:松开b1改变按钮自身颜色
	connect(b1, &QPushButton::released, this, &MainWidget::ChangeBtnTitile);

	this->setWindowTitle("主窗体");

	b2.setParent(this);
	b2.setText("切换到子窗体");
	b2.move(50, 50);

	//显示子窗体
//    sw.show();

	//子窗体切换按钮完成
	connect(&b2, &QPushButton::released, this, &MainWidget::ExchangeWin);

	//处理子窗口按钮的信号
	//定义不带参数信号函数指针
//    void (SubWidget::*NoParams)() = &SubWidget::mySignal;
//    connect(&sw,NoParams,this,&MainWidget::DealSub);

	//处理子窗口有参数的信号
	//定义带参数信号函数指针
//    void (SubWidget::*HaveParams)(int,QString) = &SubWidget::mySignal;
//    connect(&sw,HaveParams,this,&MainWidget::DealSlot);

	// QT4信号连接的方式
	//QT4槽函数必须有slots关键字修饰
	connect(&sw, SIGNAL(mySignal()), this, SLOT(DealSub()));
	connect(&sw, SIGNAL(mySignal(int, QString)), this, SLOT(DealSlot(int, QString)));
	//SIGNAL    SLOT 将函数名字 -> 字符串 不进行错误检查

	//Lamda表达式,匿名函数对象
	//C++11增加的新特性,项目文件: CONFIG += C++11;
	//QT配合信号一起使用,非常方便
	int a = 888, b = 999;

	QPushButton *b4 = new QPushButton(this);
	b4->setText("Lamda表达式");
	b4->move(150, 150);
	connect(b4, &QPushButton::clicked/*有默认参数*/,
		//信号接收者this可以省略,和槽函数一起使用Lamda表达式
		[=](/*修改默认参数*/bool isCheck) mutable//=:将外部所有局部变量,类中所有成员以值得传达方式传进来_推荐使用
					//this:类中所有成员以值得传达方式传进来
					//&:把外部局部变量,引用进来_不建议使用
	{
		b4->setText("I Love You");
		qDebug() << "11111111";
		qDebug() << a + b;
		//增加mutable可以修改传入的参数
		a += 1000;
		qDebug() << a + b;
		//打印clicked的参数
		qDebug() << isCheck;//false
	});
}

MainWidget::~MainWidget()
{

}
//改变按钮标题槽函数的具体实现
void MainWidget::ChangeBtnTitile()
{
	b.setText("123");
	b1->setText("abc");
}
//自定义窗体交互的槽函数
void MainWidget::ExchangeWin()
{
	//子窗口显示
	sw.show();
	//本窗口隐藏
	this->hide();
}
//实现自定义子窗体按钮槽函数
void MainWidget::DealSub()
{
	//本窗体显示
	this->show();
	//子窗体关闭
	sw.hide();
}
//实现自定义带参数的槽函数
void MainWidget::DealSlot(int num, QString str)
{
	//str.toUtf8() -> 字节数组QByteArray
	//.data() -> char *
	qDebug() << num << str.toUtf8().data();
}
