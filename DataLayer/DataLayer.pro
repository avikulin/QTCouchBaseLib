#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T17:21:25
#
#-------------------------------------------------

QT       -= gui

TARGET = DataLayer
TEMPLATE = lib

DEFINES += DATALAYER_LIBRARY

SOURCES += datalayer.cpp

HEADERS += datalayer.h\
        datalayer_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    dataentities.qmodel



