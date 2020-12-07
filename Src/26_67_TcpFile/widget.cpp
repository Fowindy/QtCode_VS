#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

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

	//最开始两个按钮都不能按变灰setEnabled
	ui->btnSelectFile->setEnabled(false);
	ui->btnSendFile->setEnabled(false);

	//connect如果客户端成功和服务器连接tcpServer会自动触发newconnection()信号
	connect(tcpServer, &QTcpServer::newConnection,
		[=]() {
		//取出建立好连接的套接字_tcpServer->nextPendingConnection
		tcpSocket = tcpServer->nextPendingConnection();

		//获取对方的ip和端口_tcpSocket->peerAddress_tcpSocket->peerPort
		QString ip = tcpSocket->peerAddress().toString();
		quint16 port = tcpSocket->peerPort();

		//拼接提示字符串
		QString str = QString("[%1:%2] 连接服务器成功!").arg(ip).arg(port);

		//显示到界面编辑区
		ui->textEdit->setText(str);

		//成功连接后才可以按选择按钮setEnabled
		ui->btnSelectFile->setEnabled(true);
	});
}

Widget::~Widget()
{
	delete ui;
}

/************************************
*@Method:    on_btnSelectFile_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 11:15
*@Describe:	 选择文件按钮事件
*************************************/
void Widget::on_btnSelectFile_clicked()
{
	//选择文件对话框获取文件全路径
	QString filePath = QFileDialog::getSaveFileName(this, "Open", "../");

	if (false == filePath.isEmpty())	//如果选择文件路径有效
	{
		//先清除一下文件名称,避免上次干扰
		fileName.clear();
		//重置文件大小
		fileSize = 0;
		//初始化已发送的大小为0
		sendSize = 0;
		//只读方式打开文件,获取文件大小和名称(全局变量)
		QFileInfo info(filePath);
		fileName = info.fileName();	//获取文件名字
		fileSize = info.size();	//获取文件大小

		//指定文件的名字
		file.setFileName(filePath);

		//打开文件
		bool isok = file.open(QIODevice::ReadOnly);

		if (false == isok)
		{
			qDebug() << "只读方式打开文件失败 77";
		}

		//显示打开文件路径
		ui->textEdit->append(filePath);

		//选择文件后按钮变灰
		ui->btnSelectFile->setEnabled(false);
		//选择文件后发送按钮变亮
		ui->btnSendFile->setEnabled(true);
	}
	else	//如果选择文件路径无效
	{
		qDebug() << "选择文件路径出错 62";
	}
}

/************************************
*@Method:    on_btnSendFile_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/07 11:35
*@Describe:	 发送文件按钮事件
*************************************/
void Widget::on_btnSendFile_clicked()
{
	//先发送文件头信息_文件名##文件大小
	QString head = QString("%1##%2").arg(fileName).arg(fileSize);
	//发送头部信息
	qint64 len = tcpSocket->write(head.toUtf8());
}
