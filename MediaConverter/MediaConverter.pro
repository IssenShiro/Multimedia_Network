#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T03:33:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_MAC_SDK = macosx10.11
TARGET = MediaConverter
TEMPLATE = app

INCLUDEPATH += $$_PRO_FILE_PWD_\
            /usr/local/include/ \
            /opt/X11/include/ \
            /usr/local/libjpeg/ \
            /usr/local/libtiff/ \
            /usr/local/libpng \
            /usr/local/include/lame \

LIBS += -L/opt/X11/lib -lX11 \
        -L/usr/local/libjpeg/lib -ljpeg \
        -L/usr/local/libtiff/lib -ltiff \
        -L/usr/local/libpng/ -lpng \
        -L/usr/local/lib/ -lmp3lame

SOURCES += main.cpp\
        mainwindow.cpp \
    audioconversion.cpp \
    imageconversion.cpp \
    videoconversion.cpp

HEADERS  += mainwindow.h \
    imageconversion.h \
    videoconversion.h \
    audioconversion.h \
    namespace_lib.h \
    CImg.h

FORMS    += mainwindow.ui
