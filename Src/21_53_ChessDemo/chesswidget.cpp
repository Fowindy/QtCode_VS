#pragma execution_character_set("utf-8")
#include "chesswidget.h"

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

}

