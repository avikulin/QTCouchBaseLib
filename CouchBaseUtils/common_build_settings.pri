PROJECT_ROOT_PATH = $${PWD}

win32-msvc2013: {
                     equals(QMAKE_TARGET.arch, x86) {
                                                        OS_SUFFIX = Win32
                                                    } else
                                                    {
                                                        OS_SUFFIX = Win64
                                                    }
}

linux-g++: OS_SUFFIX = linux
CONFIG -= debug_and_release
CONFIG(debug, debug|release) {
    BUILD_FLAG = Debug
    LIB_SUFFIX = _d
} else {
    BUILD_FLAG = Release
}

BIN_PATH = $$OUT_PWD/../BIN/$${OS_SUFFIX}/$${BUILD_FLAG}
BUILD_TEMP_PATH = $${OUT_PWD}/../BUILD_TEMP
MKF_PATH = $${BUILD_TEMP_PATH}/$${BUILD_FLAG}/$$TARGET

EXT_LIBS_PATH = $${PROJECT_ROOT_PATH}/../LIBS/$${OS_SUFFIX}/Lib
EXT_INC_PATH = $${PROJECT_ROOT_PATH}/../LIBS/$${OS_SUFFIX}/Include
EXT_BIN_PATH = $${PROJECT_ROOT_PATH}/../LIBS/$${OS_SUFFIX}/Bin

INT_INC_PATH  = $$OUT_PWD/../EXPORT/Include
INT_BIN_PATH  = $$OUT_PWD/../EXPORT/BIN/$${BUILD_FLAG}
INT_LIBS_PATH = $$OUT_PWD/../EXPORT/LIBS/$${BUILD_FLAG}

RCC_DIR = $${BUILD_TEMP_PATH}/rcc/
UI_DIR = $${BUILD_TEMP_PATH}/ui/
MOC_DIR = $${BUILD_TEMP_PATH}/moc/
OBJECTS_DIR = $${BUILD_TEMP_PATH}/obj/

LIBS += -L$${EXT_LIBS_PATH}/
LIBS += -L$${INT_LIBS_PATH}/

INCLUDEPATH += $${EXT_INC_PATH}
DEPENDPATH += $${EXT_INC_PATH}
INCLUDEPATH += $${INT_INC_PATH}
DEPENDPATH += $${INT_INC_PATH}

CONFIG += c++11
DEFINES += Q_COMPILER_INITIALIZER_LISTS
