DESTDIR = $${BIN_PATH}
linux-g++: QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/
win32-msvc2013:{
                 QMAKE_POST_LINK += windeployqt --compiler-runtime $$DESTDIR
}
