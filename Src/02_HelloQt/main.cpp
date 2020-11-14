﻿#include <QApplication>
#include <QWidget> //窗口控件基类
#include <QPushButton>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    QWidget w;
    w.setWindowTitle("主要看气质");

    QPushButton b;
    b.setText("^_^");   //给按钮设置内容,对象和对象(窗口和窗口)没有关系,相互独立
//    b.show();
    b.setParent(&w);//指定父类对象
    b.move(100,100);//移动坐标

    QPushButton b1(&w);//通过构造函数传参
    b1.setText("abc");
    w.show();
    /*如果不指定父对象,对象和对象(窗口和窗口)没有关系,相互独立
     * a指定b为它的父对象, a放在b的上面
     * 指定父对象,有2种方式:
     *      1)setParent;设置父类
     *      2)通过构造函数传参
     *  指定父对象,只需要父对象显示,上面的子对象自动显示
    */

    app.exec();
    return 0;
}
