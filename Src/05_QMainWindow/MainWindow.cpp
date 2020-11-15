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

	//添加[文件]父菜单
	QMenu *pFile = mBar->addMenu("文件");

	//添加[新建]子菜单项动作
	QAction *pNew = pFile->addAction("新建");	//返回的是动作的指针
}
