#pragma execution_character_set("utf-8")
#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.setWindowTitle("MainWindow窗口");
	w.show();
	return a.exec();
}
