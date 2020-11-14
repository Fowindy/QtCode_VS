#pragma execution_character_set("utf-8")
#include "MyWidget.h"
#include "QPushButton"
#include "MyButton.h"


MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
	//因为move是从QWidget继承过来的,所以按钮和窗口都可以使用
	/**
	 * 对于父窗口(主窗口),坐标系统相当于屏幕
	 原点:相对于屏幕左下角
	 x:往右递增
	 y:往左递增
	 */
	move(100, 100);

	/**
	 * 对于子窗口(子窗口),坐标系统相当于父窗体
	 原点:相对于父窗体左下角(不包括边框)
	 x:往右递增
	 y:往左递增
	 */
	QPushButton *b1 = new QPushButton(this);
	b1->move(100, 100);
	b1->setText("^_^");
	b1->resize(100, 100);

	//b2按钮相对于b1按钮左上角偏移(10,10)
	QPushButton *b2 = new QPushButton(b1);
	b2->move(10, 10);
	b2->setText("@v@");

	MyButton *b3 = new MyButton(this);
	b3->setText("b3按钮");
	//1)指定父类对象后	2)直接或间接继承于QObject
	//子类对象如果是动态分配空间的,不需要手动delete释放,系统会自动释放
}
