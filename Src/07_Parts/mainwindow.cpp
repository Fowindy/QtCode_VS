#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//代码中重写按钮标题名和重写槽函数关闭为最大化
	ui->MyButton->setText("123");
	connect(ui->MyButton, &QPushButton::clicked, this, &MainWindow::showMaximized);

	//QLineEdit控件
	//获取内容
	QString str = ui->lineEdit->text();
	qDebug() << str;
	//设置内容
	ui->lineEdit->setText("Fowindy");
	//设置内容显示间隙
	//ui->lineEdit->setTextMargins(15, 10, 0, 0);
	//设置密码显示模式(黑点)_输入显示黑点
	//ui->lineEdit->setEchoMode(QLineEdit::Password);
	//设置密码显示模式_输入显示明码_输入完成显示黑点
	//ui->lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

	QStringList list;
	list << "hello" << "how are you" << "Here" << "window";
	QCompleter *com = new QCompleter(list, this);
	com->setCaseSensitivity(Qt::CaseInsensitive);

	ui->lineEdit->setCompleter(com);

	//QLabel_text
	ui->labelText->setText("今天天气好晴朗");
	//QLabel_image
	ui->labelImage->setPixmap(QPixmap(":/image/Luffy.png"));
	//让图片自适应label大小
	ui->labelImage->setScaledContents(true);

	//QLabel_gif
	//创建动画对象
	QMovie *myMovie = new QMovie(":/image/mario.gif");
	//设置动画
	ui->labelGif->setMovie(myMovie);
	//启动动画
	myMovie->start();
	//动画自适应大小
	ui->labelGif->setScaledContents(true);

	//QLabel_Url
	//设置html
	ui->labelUrl->setText("<h1><a href = \"https://www.baidu.com\">百度一下</a></h1>");
	//设置点击打开外部链接
	ui->labelUrl->setOpenExternalLinks(true);

	//数码管
	ui->lcdNumber->display(123);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_change_clicked()
{
	static int i = 0;	//静态的,每次不释放这个值,实现切换
	ui->stackedWidget->setCurrentIndex(++i % 3);
}

