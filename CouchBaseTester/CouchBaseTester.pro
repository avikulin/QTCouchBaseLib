QT += core
QT -= gui

CONFIG += c++11
DESTDIR = $$OUT_PWD

TARGET = CouchBaseTester
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CouchBaseAdapter/release/ -lCouchBaseAdapter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CouchBaseAdapter/debug/ -lCouchBaseAdapter
else:unix:!macx: LIBS += -L$$OUT_PWD/../CouchBaseAdapter/ -lCouchBaseAdapter

INCLUDEPATH += $$PWD/../CouchBaseAdapter
DEPENDPATH += $$PWD/../CouchBaseAdapter
