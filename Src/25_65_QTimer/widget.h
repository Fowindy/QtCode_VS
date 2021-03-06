﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();

private:
	Ui::Widget *ui;
	QTimer *timer;	//创建定时器对象
private slots:
	void on_btnStart_clicked();
	void on_btnClose_clicked();
};
#endif // WIDGET_H
