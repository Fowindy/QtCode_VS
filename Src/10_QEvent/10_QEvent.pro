# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = 10_QEvent
DESTDIR = ./debug
QT += core gui widgets
CONFIG += C++11
DEFINES += _WINDOWS _UNICODE _ENABLE_EXTENDED_ALIGNED_STORAGE WIN64 QT_DEPRECATED_WARNINGS
LIBS += -lshell32
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
HEADERS += ./widget.h \
    ./myLabel.h \
    ./myButton.h
SOURCES += ./main.cpp \
    ./myButton.cpp \
    ./myLabel.cpp \
    ./widget.cpp
FORMS += ./widget.ui
RESOURCES += widget.qrc
