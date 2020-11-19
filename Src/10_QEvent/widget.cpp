#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>


Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	sec1 = 0;
	sec2 = 0;
	ui->setupUi(this);
	timerId = this->startTimer(1000);	//以毫秒为单位	每一秒触发定时器
	this->timerId2 = this->startTimer(500);	//以毫秒为单位	每500毫秒触发定时器

	connect(ui->pushButton, &myButton::clicked,
		[=]()
	{
		qDebug() << "按钮被按下";
	});

	//label_2事件过滤器安装
	ui->label_2->installEventFilter(this);
	//label_2鼠标捕捉
	ui->label_2->setMouseTracking(true);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
	//显示键盘按键的ASCII码
	//qDebug() << ev->key();

	//键盘按键的ASCII码转换字符
	qDebug() << (char)ev->key();

	//特殊按键判断
	if (ev->key() == Qt::Key_Shift)
	{
		qDebug() << "Shift";
	}
}

void Widget::timerEvent(QTimerEvent *ev)
{
	if (ev->timerId() == this->timerId)
	{
		TimerMethod(sec1, "Timer1", ev->timerId(), ui->label);
	}
	else if (ev->timerId() == this->timerId2)
	{
		TimerMethod(sec2, "Timer2", ev->timerId(), ui->label_2);
	}
}

void Widget::TimerMethod(int &sec, QString timerType, int timerId, QLabel* label)
{
	label->setText(QString("<center><h1>%2 out: %1</h1></center>")
		.arg(++sec)
		.arg(timerType)
	);
	if (timerId == this->timerId && sec == 25)
	{
		this->killTimer(timerId);
		label->setText(QString("<center><h1><font color=red>定时器%2关闭: %1</h1></center>")
			.arg(sec)
			.arg(timerType)
		);
	}
}

void Widget::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "父组件接收到myButton的事件传递";
}

void Widget::closeEvent(QCloseEvent *event)
{
	//弹出QMessageBox来提示用户选择
	int result = QMessageBox::question(this, "关闭窗口", "确定关闭窗口?", "确定", "取消");
	if (result == 0)
	{
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == ui->label_2)
	{
		//将QEvent父类对象转换为Q
		QMouseEvent *mEnv = static_cast<QMouseEvent *>(event);
		QString color, buttonName;
		//判断按钮事件:按钮按下(左红坐标,右蓝坐标,中绿坐标)
		switch (mEnv->type())
		{
		case QEvent::MouseMove:
			return MyFilterMethod("red", "MouseMove", mEnv);
			break;
		case QEvent::MouseButtonPress:
			return MyFilterMethod("blue", "MouseButtonPress", mEnv);
			break;
		case QEvent::MouseButtonRelease:
			return MyFilterMethod("green", "MouseButtonRelease", mEnv);
			break;
		}
	}
	return QWidget::eventFilter(watched, event);
}

bool Widget::MyFilterMethod(QString color, QString buttonName, QMouseEvent * mEnv)
{
	ui->label_2->setText(QString("<center><h2><font color=%1>%4:(%2,%3)</h2></center>")
		.arg(color).arg(mEnv->x()).arg(mEnv->y()).arg(buttonName));
	return true;
}

//bool Widget::event(QEvent *e)
//{
//	//事件分发
//	switch (e->type())
//	{
//	case QEvent::MouseButtonPress:
//		//使用dynamic_cast将父类转成子类(比static_cast有检查,更安全)
//		mousePressEvent(dynamic_cast<QMouseEvent*>(e));
//		break;
//	case QEvent::Close:
//		closeEvent(dynamic_cast<QCloseEvent*>(e));
//		break;
//		/**
//		 * ......
//		 */
//	}
//	return false;
//}

bool Widget::event(QEvent *e)
{
	//    //事件分发
	//    switch( e->type() )
	//    {
	//        case QEvent::Close:
	//            closeEvent(e);
	//        break;
	//    case QEvent::MouseMove:
	//        mouseMoveEvent(e);
	//        break;
	//        /*
	//         *  ……
	//        */
	//    }

	if (e->type() == QEvent::Timer)
	{
		//干掉定时器 如果返回true，事件停止传播
#pragma region 不干掉定时器
		QTimerEvent *env = static_cast<QTimerEvent *>(e);
		timerEvent(env);
#pragma endregion

		return true;
	}
	//只获取键盘B按下才事件处理
	else if (e->type() == QEvent::KeyPress)
	{
		//类型转换
		QKeyEvent *env = static_cast<QKeyEvent *>(e);
		if (env->key() == Qt::Key_B)
		{
			return QWidget::event(e);
		}
		return true;

	}
	else
	{
		return QWidget::event(e);
	}
}

