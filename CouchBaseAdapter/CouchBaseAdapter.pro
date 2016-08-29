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
    couchbasedatasource.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LIBS/x64/Win/lib/ -llibcouchbase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LIBS/x64/Win/lib/ -llibcouchbase_d

INCLUDEPATH += $$PWD/../LIBS/x64/Win/Include
DEPENDPATH += $$PWD/../LIBS/x64/Win/Include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CouchBaseUtils/release/ -lCouchBaseUtils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CouchBaseUtils/debug/ -lCouchBaseUtils
else:unix: LIBS += -L$$OUT_PWD/../CouchBaseUtils/ -lCouchBaseUtils

INCLUDEPATH += $$PWD/../CouchBaseUtils
DEPENDPATH += $$PWD/../CouchBaseUtils
