#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
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
	QTcpSocket* tcpSocket;	//通信套接字对象
	QFile recvfile;	//接收文件对象
	QString recvfileName;	//接收文件名字
	qint64 recvFileSize;	//接收文件大小
	qint64 recvSize;	//已接收文件大小
	bool isStart;	//定义标记开头
};
#endif // WIDGET_H
