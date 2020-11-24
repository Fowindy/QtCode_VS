#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QWidget>

class ChessWidget : public QWidget
{
	Q_OBJECT

public:
	ChessWidget(QWidget *parent = nullptr);
	~ChessWidget();
protected:
	//重写绘图事件
	void paintEvent(QPaintEvent *);
private:
	int gridW;	//棋盘水平方向一个格子的宽度
	int gridH;	//棋盘水平方向一个格子的高度
	int startX;	//棋盘起点x坐标
	int startY; //棋盘起点y坐标
};
#endif // CHESSWIDGET_H
