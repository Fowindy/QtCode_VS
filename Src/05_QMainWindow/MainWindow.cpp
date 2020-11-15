#pragma execution_character_set("utf-8")
#include "MainWindow.h"
#include <QMenuBar>	//菜单栏头文件
#include <QMenu>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	resize(800, 400);
	//菜单栏实例化
	QMenuBar *mBar = menuBar();

	//添加[文件]父菜单
	QMenu *pFile = mBar->addMenu("文件");

	//添加[新建]子菜单项动作
	QAction *pNew = pFile->addAction("新建");	//返回的是动作的指针
	//定义按下次数变量
	int num = 0;

	//连接[新建]动作
	connect(pNew, &QAction::triggered,
		[=]()mutable	//=:可以访问变量;mutable:可以对变量进行操作
	{
		qDebug() << "新建被按下" << ++num;
	}
	);

	//添加[新建]和[打开]中间分割线
	pFile->addSeparator();

	//添加[打开]子菜单项
	QMenu *pOpen = pFile->addMenu("打开");
	//添加[打开]的子菜单[项目]动作
	QAction *pProject = pOpen->addAction("项目");
	//连接[项目]动作
	num = 0;
	connect(pProject, &QAction::triggered,
		[=]()mutable
	{
		qDebug() << "项目被按下" << num++;
	}
	);
	//添加[项目]和[文件夹]分割线
	pOpen->addSeparator();
	//添加[打开]的子菜单[文件夹]动作
	QAction *pDirectory = pOpen->addAction("文件夹");
	//连接[文件夹]动作
	num = 0;
	connect(pDirectory, &QAction::triggered,
		[=]()mutable
	{
		qDebug() << "文件夹被按下" << num++;
	}
	);

#pragma region 工具栏
	//工具栏:本质是菜单项的快捷方式
	QToolBar *toolBar = addToolBar("toolBar");
	//工具栏添加[新建]快捷键动作
	toolBar->addAction(pNew);

	//工具栏添加按钮样式[项目]的快捷方式
	QPushButton *pBtnProject = new QPushButton(toolBar);
	pBtnProject->move(130, 0);
	pBtnProject->setText("项目");
	//工具栏添加[新建]快捷键动作_切换为Project
	connect(pBtnProject, &QPushButton::clicked,
		[=]()mutable
	{
		pBtnProject->setText("Project");
	});

	//工具栏添加按钮样式[文件夹]的快捷方式
	QPushButton *pBtnDirectory = new QPushButton(this);
	pBtnDirectory->setText("文件夹");
	//推荐---将按钮绑定到工具栏---方式
	toolBar->addWidget(pBtnDirectory);
	//工具栏添加[文件夹]快捷键动作_切换为Directory
	connect(pBtnDirectory, &QPushButton::clicked,
		[=]()
	{
		pBtnDirectory->setText("Directory");
	});
#pragma endregion
}
