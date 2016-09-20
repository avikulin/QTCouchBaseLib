
DESTDIR = $${MKF_PATH}

win32-msvc2013:{
                    DLLDESTDIR += $$shell_path($${BIN_PATH})

                    targetLIBS.path = $$shell_path($${BIN_PATH})
                    targetLIBS.files = $$shell_path($${MKF_PATH}/*.lib)
                    INSTALLS +=targetLIBS

                    targetEXPS.path = $$shell_path($${BIN_PATH})
                    targetEXPS.files = $$shell_path($${MKF_PATH}/*.exp)
                    INSTALLS +=targetEXPS

                    targetDLLs.path = $$shell_path($${INT_BIN_PATH})
                    targetDLLs.files = $$shell_path($${MKF_PATH}/*.dll)
                    INSTALLS +=targetDLLs

                    targetLIBS2.path = $$shell_path($${INT_LIBS_PATH})
                    targetLIBS2.files = $$shell_path($${MKF_PATH}/*.lib)
                    INSTALLS +=targetLIBS2

                    targetEXPS2.path = $$shell_path($${INT_LIBS_PATH})
                    targetEXPS2.files = $$shell_path($${MKF_PATH}/*.exp)
                    INSTALLS +=targetEXPS2
               }
unix:          {
                    target.path = /usr/lib
                    INSTALLS += target
               }
CONFIG += skip_target_version_ext
VERSION = 1.0.0
QMAKE_TARGET_COPYRIGHT = Andrey Vikulin

headers.path    = $$INT_INC_PATH
headers.files   += $${HEADERS}
INSTALLS        += headers

win32-msvc2013:{
                    BaseCMDshell = "cmd /c"

                    BaseCOPYcmd = "& xcopy /S /I /C /Y"
                    cp_commands += $${BaseCOPYcmd} $$shell_path($${EXT_LIBS_PATH}) $$shell_path($${BIN_PATH})
                    cp_commands += $${BaseCOPYcmd} $$shell_path($${EXT_BIN_PATH}) $$shell_path($${BIN_PATH})

                    cmd_list = ""
                    for (cmd, cp_commands):{
                                                cmd_list = $${cmd_list} $${cmd}
                                           }
                    mv_commands = $${BaseCOPYcmd}
                    mv_commands += $$shell_path($${OUT_PWD}) $$shell_path($${MKF_PATH})
                    mv_commands += ">nul 2>&1"
#                    mv_commands += "& rmdir /S /Q"
#                    mv_commands += $$shell_path($${OUT_PWD})
#                    mv_commands += ">nul 2>&1"

                    moveMakeDir.commands = $${BaseCMDshell} $$quote($${mv_commands})

                    Copy_CMD.commands = $${BaseCMDshell} $$quote($${cmd_list})
               }

QMAKE_EXTRA_TARGETS += Copy_CMD
POST_TARGETDEPS += Copy_CMD
QMAKE_POST_LINK += $${moveMakeDir.commands}
