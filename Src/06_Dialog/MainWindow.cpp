#pragma execution_character_set("utf-8")
#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//创建一个菜单栏_第一种方式:父类成员函数构造QMenuBar对象_推荐
	//QMenuBar *mBar = menuBar();
#pragma region 第二种方式:直接new实例化,这种方式需要调用setMenuBar设置_不推荐
	QMenuBar *mBar = new QMenuBar();
	//实例化的方式需要将对象调用父setMenuBar设置
	setMenuBar(mBar);
#pragma endregion

	//给菜单栏中添加[对话框菜单]
	QMenu *menu = mBar->addMenu("对话框");

	//给[对话框]菜单添加子[模态对话框]动作
	QAction *qaDlg = menu->addAction("模态对话框");
	//连接动作
	connect(qaDlg, &QAction::triggered,
		[=]()
	{
		QDialog qDlg;
		qDlg.exec();//exec会阻塞进程,一直显示
		qDebug() << "模态对话框";	//模态对话框关闭的时候才会显示
	}
	);
}
MainWindow::~MainWindow()
{

}