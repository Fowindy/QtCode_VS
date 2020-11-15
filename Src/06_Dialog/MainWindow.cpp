#pragma execution_character_set("utf-8")
#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//创建一个菜单栏_第一种方式:父类成员函数构造QMenuBar对象_推荐
	QMenuBar *mBar = menuBar();
	//给菜单栏中添加[对话框菜单]
	QMenu *menu = mBar->addMenu("对话框");
}
MainWindow::~MainWindow()
{

}