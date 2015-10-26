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
            /usr/local/include/

#LIBS += -L/usr/local/lib/libmp3lame.dylib -lpsapi

SOURCES += main.cpp\
        mainwindow.cpp \
    audioconversion.cpp \
    imageconversion.cpp \
    videoconversion.cpp

HEADERS  += mainwindow.h \
    imageconversion.h \
    videoconversion.h \
    audioconversion.h \
    namespace_lib.h

FORMS    += mainwindow.ui
