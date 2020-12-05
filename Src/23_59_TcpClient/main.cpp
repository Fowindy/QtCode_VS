#pragma execution_character_set("utf-8")
#include "ClientWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ClientWidget w;
	w.show();
	return a.exec();
}
