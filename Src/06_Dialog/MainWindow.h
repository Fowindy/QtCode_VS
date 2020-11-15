#pragma once

#include <QtWidgets/QMainWindow>
#include <QDialog>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
private:
	QDialog qDlg;
};
