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
    couchbasedatacource.cpp \
    couchbasedocument.cpp \
    couchbaseclientcookie.cpp

HEADERS += couchbaseadapter.h\
        couchbaseadapter_global.h \
    couchbasedatacource.h \
    couchbasedocument.h \
    couchbaseclientcookie.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LIBS/libcouchbase-2.6.1_amd64_vc11/lib/ -llibcouchbase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LIBS/libcouchbase-2.6.1_amd64_vc11/lib/ -llibcouchbase_d

INCLUDEPATH += $$PWD/../LIBS/libcouchbase-2.6.1_amd64_vc11/include
DEPENDPATH += $$PWD/../LIBS/libcouchbase-2.6.1_amd64_vc11/include
