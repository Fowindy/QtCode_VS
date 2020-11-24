#pragma execution_character_set("utf-8")
#include "chesswidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChessWidget w;
	w.show();
	return a.exec();
}
