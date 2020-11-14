#-------------------------------------------------
#
# Project created by QtCreator 2020-11-12T21:41:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03_SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    subwidget.cpp

HEADERS  += mainwidget.h \
    subwidget.h

CONFIG += C++11
