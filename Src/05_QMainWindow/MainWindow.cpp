#pragma execution_character_set("utf-8")
#include "MainWindow.h"
#include <QMenuBar>	//菜单栏头文件
#include <QMenu>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//菜单栏实例化
	QMenuBar *mBar = menuBar();
}
