QT += core
QT -= gui

TARGET = CouchBaseTester

CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

TEMPLATE = app

SOURCES += main.cpp

include (../CouchBaseUtils/common_build_settings.pri)
include (../CouchBaseUtils/app_settings.pri)

LIBS += -lCouchBaseAdapter
