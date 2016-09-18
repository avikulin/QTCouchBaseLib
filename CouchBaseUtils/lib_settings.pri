DESTDIR = $${BIN_PATH}/
win32-msvc2013:{
                    DLLDESTDIR = $${BIN_PATH}
               }
unix:          {
                    target.path = /usr/lib
                    INSTALLS += target
               }

VERSION = 1.0.0
QMAKE_TARGET_COPYRIGHT = (c) Andrey Vikulin

INT_LIBS_PATH = $$BIN_PATH
INT_INC_PATH = $$BIN_PATH/include/
INT_BIN_PATH = $$BIN_PATH

headers.path    = INT_INC_PATH
headers.files   += $$HEADERS
INSTALLS        += headers
