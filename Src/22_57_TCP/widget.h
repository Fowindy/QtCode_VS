#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字

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
	QTcpServer *tcpServer;	//监听套接字
	QTcpSocket *tcpSocket;	//通信套接字
	//指针和变量:用指针要动态分配空间,用变量要去地址符
private slots:
	void sendMessage();	//[qt4方式]_发信息
	void on_btnSend_clicked();
};
#endif // WIDGET_H
