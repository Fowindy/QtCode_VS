#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtCode_VS.h"

class QtCode_VS : public QWidget
{
    Q_OBJECT

public:
    QtCode_VS(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtCode_VSClass ui;
};
