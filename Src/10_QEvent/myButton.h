#pragma once

#include <QPushButton>

class myButton : public QPushButton
{
	Q_OBJECT

public:
	myButton(QWidget *parent);
	~myButton();
protected:
	//重写此按钮鼠标按下事件
	void mousePressEvent(QMouseEvent *e);
};
