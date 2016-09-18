CONFIG += depend_includepath

PROJECT_ROOT_PATH = $${PWD}/

CONFIG(debug, debug|release): CONFIG = debug
CONFIG(release, debug|release): CONFIG = release

win32-msvc2013: {
                    equals(QMAKE_TARGET.arch, x86) {
                                                        OS_SUFFIX = Win32
                                                    } else
                                                    {
                                                        OS_SUFFIX = Win64
                                                    }
}

linux-g++: OS_SUFFIX = linux

CONFIG(debug, debug|release) {
    BUILD_FLAG = debug
    LIB_SUFFIX = _d
} else {
    BUILD_FLAG = release
}

BIN_PATH = $$OUT_PWD/../RES/bin/$${OS_SUFFIX}/$${BUILD_FLAG}

INT_LIBS_PATH = $$BIN_PATH
INT_INC_PATH = $$BIN_PATH/include/
INT_BIN_PATH = $$BIN_PATH

EXT_LIBS_PATH = $${PROJECT_ROOT_PATH}/LIBS/$${OS_SUFFIX}/lib/
EXT_INC_PATH = $${PROJECT_ROOT_PATH}/LIBS/$${OS_SUFFIX}/include/
EXT_BIN_PATH = $${PROJECT_ROOT_PATH}/LIBS/$${OS_SUFFIX}/bin

BUILD_TEMP_PATH = $$OUT_PWD/build_temp/$${BUILD_FLAG}/$${TARGET}/

RCC_DIR = $${BUILD_TEMP_PATH}/rcc/
UI_DIR = $${BUILD_TEMP_PATH}/ui/
MOC_DIR = $${BUILD_TEMP_PATH}/moc/
OBJECTS_DIR = $${BUILD_TEMP_PATH}/obj/

LIBS += -L$${EXT_LIBS_PATH}/
#INCLUDEPATH += $$[QTDIR]/include/
#DEPENDPATH += $$[QTDIR]/include/
INCLUDEPATH += $${EXT_INC_PATH}/
DEPENDPATH += $${EXT_INC_PATH}/
INCLUDEPATH += $${INT_INC_PATH}/
DEPENDPATH += $${INT_INC_PATH}/

CONFIG += c++11

ext_libs.path    = $$BIN_PATH
ext_libs.files   += $$LIBS
INSTALLS       += ext_libs
