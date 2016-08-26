#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T19:13:05
#
#-------------------------------------------------

QT       -= gui

TARGET = CouchBaseUtils
TEMPLATE = lib

DEFINES += COUCHBASEUTILS_LIBRARY

SOURCES += couchbaseutils.cpp

HEADERS += couchbaseutils.h\
        couchbaseutils_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
