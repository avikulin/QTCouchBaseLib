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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LIBS/x64/Win/lib/ -llibcouchbase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LIBS/x64/Win/lib/ -llibcouchbase_d

INCLUDEPATH += $$PWD/../LIBS/x64/Win/Include
DEPENDPATH += $$PWD/../LIBS/x64/Win/Include
