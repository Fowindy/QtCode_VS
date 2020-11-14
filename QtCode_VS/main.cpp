#include "QtCode_VS.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCode_VS w;
    w.show();
    return a.exec();
}
