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
	void sendData();	//发送文件数据

private:
	Ui::Widget *ui;
	QTcpServer *tcpServer;	//监听套接字对象
	QTcpSocket *tcpSocket;	//通信套接字对象
	QFile file;	//文件对象
	QString fileName;	//文件名字
	qint64 fileSize;	//文件大小
	qint64 sendSize;	//已发送文件大小

private slots:
	void on_btnSelectFile_clicked();
	void on_btnSendFile_clicked();
};
#endif // WIDGET_H
