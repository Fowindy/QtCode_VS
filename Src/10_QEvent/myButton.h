#pragma once

#include <QPushButton>

class myButton : public QPushButton
{
	Q_OBJECT

public:
	myButton(QWidget *parent);
	~myButton();
};
