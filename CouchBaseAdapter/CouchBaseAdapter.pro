#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T21:08:50
#
#-------------------------------------------------

QT       += core
QT       -= gui
CONFIG   += qt

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

include (../CouchBaseUtils/common_build_settings.pri)
include (../CouchBaseUtils/lib_settings.pri)

LIBS += -llibcouchbase$$LIB_SUFFIX
