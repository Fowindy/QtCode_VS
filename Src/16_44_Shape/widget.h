#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>

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
	void paintEvent(QPaintEvent *event);
	//鼠标按下_按下鼠标坐标与窗口左上角坐标转换
	void mousePressEvent(QMouseEvent *event);
	//鼠标移动_转换后的坐标加上移动偏移量
	void mouseMoveEvent(QMouseEvent *event);

private:
	Ui::Widget *ui;
	QPoint point;
	QPoint point1;
};
#endif // WIDGET_H
