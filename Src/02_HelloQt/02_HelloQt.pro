#QT += widgets   #注意!!!此处widgets首字母为小写 5.13版本不能用这一行 需要用下面的

#报错:QApplication: No such file or directory的解决方法
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp
