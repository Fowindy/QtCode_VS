#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myLabel.h"
#include "myButton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();
protected:
	//键盘按下事件
	void keyPressEvent(QKeyEvent *);	//占位符参数，方便以后修改函数定义且不需要修改接口
	//计时器事件
	void timerEvent(QTimerEvent *);

	void TimerMethod(int &sec, QString timerType, int timerId, QLabel* label);
	//父组件鼠标按下事件验证传递
	void mousePressEvent(QMouseEvent *event);

	//案例:父组件关闭窗口,提示是否关闭
	void closeEvent(QCloseEvent *event);

	//重写event事件
	bool event(QEvent *);

	//事件过滤器
	bool eventFilter(QObject *watched, QEvent *event);

	bool MyFilterMethod(QString color, QString buttonName, QMouseEvent * mEnv);

private:
	Ui::Widget *ui;
	int timerId;	//定义定时器的Id
	int timerId2;	//定义定时器Id2
	int sec1;
	int sec2;
};
#endif // WIDGET_H
