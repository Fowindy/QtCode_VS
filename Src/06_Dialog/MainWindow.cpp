#pragma execution_character_set("utf-8")
#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

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

#pragma region 模态对话框
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
#pragma endregion

#pragma region 非模态对话框
	QAction *dlg = menu->addAction("非模态对话框");
	connect(dlg, &QAction::triggered,
		[=]()
	{
		//QDialog qDlg;//1.看到窗口的第一种方式:将对话框以变量的形式定义在全局头文件中
		//QDialog *qDlg = new QDialog(this);//2.1.局部变量的方式,但是如果整个程序不结束的话,会一直占用内存

		//2.2.模态对话框关闭的时候释放内存
		QDialog *qDlg = new QDialog;
		qDlg->setAttribute(Qt::WA_DeleteOnClose);
		qDlg->show();//非模态用show显示,不会阻塞进程,此句执行完毕便释放,看不到窗口
		qDebug() << "非模态对话框";
	});
#pragma endregion

#pragma region 关于对话框
	QAction *qAbout = menu->addAction("关于");
	connect(qAbout, &QAction::triggered,
		[=]()
	{
		QMessageBox::about(this, "About", "关于Qt的版本介绍");
	});
#pragma endregion

#pragma region 问题对话框
	QAction *pQuestion = menu->addAction("问题对话框");
	connect(pQuestion, &QAction::triggered,
		[=]()
	{
		int result = QMessageBox::question(this, "请选择!!!", "Are you OK?");
		switch (result)
		{
		case QMessageBox::Yes:
			qDebug() << "I am OK.";
			break;
		case QMessageBox::No:
			qDebug() << "I am bad.";
			break;
		default:
			break;
		}
	});
#pragma endregion

#pragma region 问题对话框_使用自选按钮
	QAction *pQuestion1 = menu->addAction("问题对话框_自选");
	connect(pQuestion1, &QAction::triggered,
		[=]()
	{
		int result = QMessageBox::question(this, "请选择!!!", "你吃了吗?", "吃了", "没吃", "过会吃");
		switch (result)
		{
		case 0:
			qDebug() << "吃过了";
			break;
		case 1:
			qDebug() << "还没吃呢";
			break;
		case 2:
			qDebug() << "过会去吃";
			break;
		default:
			break;
		}
	});
#pragma endregion

#pragma region 文件对话框+可选格式
	QAction *pFile = menu->addAction("文件对话框");
	connect(pFile, &QAction::triggered,
		[=]()
	{
		QString url = QFileDialog::getOpenFileName(
			//父类
			this,
			//文件对话框标题
			"open",
			//文件对话框默认路径
			"../",
			//文件对话框+可选的格式
			"Source(*.cpp *.h);;Text(*.txt);;Image(*.png *.jpg);;All(*.*)");
		qDebug() << url;	//输出完整路径
	});
#pragma endregion


}
MainWindow::~MainWindow()
{

}