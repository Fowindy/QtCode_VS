#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	//给套接字分配空间_指定父对象_回收空间_不指定也可以
	udpSocket = new QUdpSocket(this);
	//udpSocket->bind绑定(8888)
	udpSocket->bind(8888);
	//设置窗口标题
	setWindowTitle("服务器端口为:8888");
	//当对方成功发送数据过来自动触发readyRead()信号
	//this当前窗口接收_&Widget::delMessage当前窗口槽函数:接收后处理
	connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::delMessage);
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    delMessage
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 21:51
*@Describe:	 处理接收的消息的槽函数_因为信号无参数所以槽函数无参数
*************************************/
void Widget::delMessage()
{
	//定义一个1024长度的char字符数组_用于存储读取到的接收内容
	char buf[1024] = { 0 };
#pragma region 方法一:使用变量
	////定义对方地址变量_和端口变量
	//QHostAddress address;
	////定义quint16类型的端口变量_注意quint16不是qint16
	//quint16 port;
	////定义长度变量,获取readDatagram读取内容返回长度
	//qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &address, &port);
#pragma endregion
#pragma region 方法二:使用指针
	//定义对方地址指针
	QHostAddress* address;
	//定义定义quint16类型的端口指针_注意quint16不是qint16
	quint16* port;
	//定义长度变量,获取readDatagram读取内容返回长度
	qint64 len = udpSocket->readDatagram(buf, sizeof(buf), address, port);
#pragma endregion
	//如果长度大于0说明读到内容不为空
	if (len > 0)
	{
		//格式化要显示的字符串
		QString str = QString("[%1:%2]:%3")
			.arg(address->toString())
			.arg(*port)
			.arg(buf);
		//将格式化好的字符串setText显示到窗口
		ui->textEdit->setText(str);
	}
}

/************************************
*@Method:    on_btnSend_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/05 22:31
*@Describe:	 发送按钮
*************************************/
void Widget::on_btnSend_clicked()
{
	//先获取对方的ip和端口
	QString ip = ui->lineEditIP->text();
	qint16 port = ui->lineEditPort->text().toInt();
	//判断ip和端口是否为空,为空提示返回
	if (ip.isEmpty() || port == 0)
	{
		QMessageBox::information(NULL, "错误", "ip和端口号均不能为空!!!");
		return;
	}
	//toPlainText获取编辑区的所有内容
	QString str = ui->textEdit->toPlainText();
}
