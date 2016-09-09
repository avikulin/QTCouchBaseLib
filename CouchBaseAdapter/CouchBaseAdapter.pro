#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T21:08:50
#
#-------------------------------------------------

QT       -= gui

TARGET = CouchBaseAdapter
TEMPLATE = lib

DEFINES += COUCHBASEADAPTER_LIBRARY

SOURCES += couchbaseadapter.cpp \
    couchbasedocument.cpp \
    couchbaseclientcookie.cpp \
    couchbasedatasource.cpp \
    couchbaseexception.cpp


HEADERS += couchbaseadapter.h\
        couchbaseadapter_global.h \
    couchbasedocument.h \
    couchbaseclientcookie.h \
    couchbasedatasource.h \
    couchbaseexception.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:LIBS += -L$$PWD/../LIBS/x64/Win/lib/ -llibcouchbase
else:win32:LIBS += -L$$PWD/../LIBS/x64/Win/lib/ -llibcouchbase_d

INCLUDEPATH += $$PWD/../LIBS/x64/Win/Include
DEPENDPATH += $$PWD/../LIBS/x64/Win/Include

