#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T19:13:05
#
#-------------------------------------------------
QT       += core
QT       -= gui

CONFIG += qt

TARGET = CouchBaseUtils
TEMPLATE = lib

DEFINES += COUCHBASEUTILS_LIBRARY

SOURCES += couchbaseutils.cpp \
    qstringconverter.cpp

HEADERS += couchbaseutils.h\
        couchbaseutils_global.h \
    qstringconverter.h

DISTFILES += \
    app_settings.pri \
    common_build_settings.pri \
    lib_settings.pri \
    qmake.commands


include (../CouchBaseUtils/common_build_settings.pri)
include (../CouchBaseUtils/lib_settings.pri)
