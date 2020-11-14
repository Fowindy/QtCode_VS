#pragma once
#pragma execution_character_set("utf-8")
#include <QPushButton>

class MyButton : public QPushButton
{
	Q_OBJECT

public:
    MyButton(QWidget *parent = Q_NULLPTR);
	~MyButton();

private:
};
