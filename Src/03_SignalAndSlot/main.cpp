#include "mainwidget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWidget w;//先执行MainWidget基类的构造函数
	w.show();
	return a.exec();
}
