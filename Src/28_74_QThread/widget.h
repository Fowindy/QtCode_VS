#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>	//定时器头文件

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
	QTimer *myTimer;	//声明定时器变量
private slots:
	void dealTimeout();	//定时器槽函数
	void on_btnStart_clicked();
};
#endif // WIDGET_H
