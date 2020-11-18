#include "SmallWidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

SmallWidget::SmallWidget(QWidget *parent)
	: QWidget(parent)
{
	//创建自增整型控件对象
	QSpinBox *spin = new QSpinBox(this);
	//创建滑块控件对象
	QSlider *slider = new QSlider(Qt::Horizontal, this);

	//创建水平布局管理器对象_不指定---[1]
	//QHBoxLayout *hLayout = new QHBoxLayout;
	//创建水平布局管理器对象_指定
	QHBoxLayout *hLayout = new QHBoxLayout(this);

	//添加控件
	hLayout->addWidget(spin);
	hLayout->addWidget(slider);

	//如果不指定,则需要下面这一步---[1]
	//setLayout(hLayout);
}

SmallWidget::~SmallWidget()
{
}
