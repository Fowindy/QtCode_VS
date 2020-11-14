#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "subwidget.h"
#include <QPushButton>
#pragma execution_character_set("utf-8")

#include <QWidget>

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();
public slots:
	//自定义改变按钮标题的槽函数
	void ChangeBtnTitile();
	//自定义窗体交互的槽函数
	void ExchangeWin();
	//自定义子窗体按钮槽函数
	void DealSub();
	//自定义带参数的槽函数
	void DealSlot(int, QString);
private:
	//创建QPushButton变量
	QPushButton b;
	QPushButton *b1;//指针
	//创建一个"切换到子窗体"的按钮
	QPushButton b2;
	//创建子窗体对象
	SubWidget sw;
};

#endif // MAINWIDGET_H
