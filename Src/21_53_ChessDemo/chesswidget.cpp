#pragma execution_character_set("utf-8")
#include "chesswidget.h"
#include <QPainter>

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
}

