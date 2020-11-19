#pragma once

#include <QLabel>

class myLabel : public QLabel
{
	Q_OBJECT

public:
	myLabel(QWidget *parent);
	~myLabel();
protected:
	//子类头文件重写父类虚函数(声明)_鼠标按下
	void mousePressEvent(QMouseEvent *ev);

	void MyMethod(QMouseEvent* ev);
	//MyMethod方法重载
	void MyMethod(QEvent* ev);
	//子类头文件重写父类虚函数(声明)_鼠标释放
	void mouseReleaseEvent(QMouseEvent *ev);
	//子类头文件重写父类虚函数(声明)_鼠标移动
	void mouseMoveEvent(QMouseEvent *ev);
	//子类头文件重写父类虚函数(声明)_进入事件
	void enterEvent(QEvent *);	//占位符参数，方便以后修改函数定义且不需要修改接口
	//子类头文件重写父类虚函数(声明)_离开事件
	void leaveEvent(QEvent *);

signals:
public slots:
};
