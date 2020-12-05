#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

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
	QUdpSocket *udpSocket;	//udp套接字
private slots:
	void delMessage();	//处理接收的消息的槽函数_因为信号无参数所以槽函数无参数
	void on_btnSend_clicked();
};
#endif // WIDGET_H
