#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>	//监听套接字
#include <QTcpSocket>	//通信套接字
#include <QFile>

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
	QTcpServer *tcpServer;	//监听套接字对象
	QTcpSocket *tcpSocket;	//通信套接字对象
	QFile file;	//文件对象
};
#endif // WIDGET_H
