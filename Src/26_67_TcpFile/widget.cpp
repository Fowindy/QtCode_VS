#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//监听套接字对象实例化
	tcpServer = new QTcpServer(this);

	//tcpServer->listen监听
	tcpServer->listen(QHostAddress::AnyIPv4, 8888);

	//setWindowTitle设置服务器窗口标题提示
	setWindowTitle("服务器端口为:8888");

	//connect如果客户端成功和服务器连接tcpServer会自动触发newconnection()信号
	connect(tcpServer, &QTcpServer::newConnection,
		[=]() {
	});
}

Widget::~Widget()
{
	delete ui;
}
