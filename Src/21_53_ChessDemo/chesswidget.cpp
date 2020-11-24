#pragma execution_character_set("utf-8")
#include "chesswidget.h"
#include <QPainter>
#include <QPixmap>
#include <QPen>

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
	//painter.drawPixmap(50, 50, 200, 200, QPixmap(":/Image/bk.jpg"));

	//[推荐]---填充窗口式画图,优点:随窗口拉伸变化
	painter.drawPixmap(rect(), QPixmap(":/Image/bk.jpg"));

	/**
	 * 设置画笔
	 */
	QPen pen;
	//设置画笔线宽
	pen.setWidth(4);
	//设置画笔颜色
	//pen.setColor(Qt::darkBlue);	//省略此句默认黑色
	//将画笔交给画家
	painter.setPen(pen);

	/**
	 * 画棋盘
	 * 第一格的四点坐标分别是:
	 * X起点:(startX,startY)				X终点:(startX+gridW,startY)
	 * Y起点:(startX,startY+gridH)		Y终点:(startX+gridW,startY+gridH)
	 *
	 * 横向最后一格的四点坐标为:
	 * X起点:(startX+7*gridW,startY)				X终点:(startX+8*gridW,startY)
	 * Y起点:(startX,startY+gridH)		Y终点:(startX+gridW,startY+gridH)
	 */
	 //取中间8份画棋盘_9条线才有8个间隔
	for (int i = 0; i < 9; i++)
	{
		//横线
		//第一条横线
		//painter.drawLine(startX, startY, startX + 8 * gridW, startY);

		//所有横线
		painter.drawLine(startX, startY + i * gridH, startX + 8 * gridW, startY + i * gridH);

		//第一条竖线
		//painter.drawLine(startX, startY, startX, startY + 8 * gridH);

		//所有竖线
		painter.drawLine(startX + i * gridW, startY, startX + i * gridW, startY + 8 * gridH);
	}
}

