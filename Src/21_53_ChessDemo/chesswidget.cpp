#pragma execution_character_set("utf-8")
#include "chesswidget.h"
#include <QPainter>
#include <QPixmap>

ChessWidget::ChessWidget(QWidget *parent)
	: QWidget(parent)
{
}

ChessWidget::~ChessWidget()
{
}

void ChessWidget::paintEvent(QPaintEvent *)
{
#pragma region 窗口宽高均分10份
	gridW = width() / 10;
	gridH = height() / 10;
#pragma endregion

	//棋盘起点坐标
	startX = gridW;
	startY = gridH;

	//创建画家对象_指定窗口为绘图设备
	QPainter painter(this);

	//画家画背景图
	//[不推荐]:指定位置和大小画图,缺点:固定,不会随窗口拉伸变化
	painter.drawPixmap(50, 50, 200, 200, QPixmap(":/Image/bk.jpg"));
}

