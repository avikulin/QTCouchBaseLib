QT += core
QT -= gui



CONFIG += c++11

TARGET = CouchBaseTester
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

TEMPLATE = app

SOURCES += main.cpp



INCLUDEPATH += $$PWD/../CouchBaseAdapter
DEPENDPATH += $$PWD/../CouchBaseAdapter

include (../CouchBaseUtils/common_build_settings.pri)
include (../CouchBaseUtils/app_settings.pri)

LIBS += -lCouchBaseAdapter$$LIB_SUFFIX
