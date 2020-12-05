#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>	//通讯套接字

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
	Q_OBJECT

public:
	ClientWidget(QWidget *parent = nullptr);
	~ClientWidget();

private:
	Ui::ClientWidget *ui;
	QTcpSocket *tcpSocket;	//通信套接字对象
private slots:
	void on_btnConnect_clicked();
	void on_btnSend_clicked();
	void on_btnClose_clicked();
};
#endif // WIDGET_H
