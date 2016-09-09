QT += core
QT -= gui

CONFIG += c++11

TARGET = CouchBaseTester
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

message("....")

BUILD_FOLDER = "Windows - "$$OUT_PWD"!!!"
message($$BUILD_FOLDER)

CURRENT_DIR = $$join("Current dir - ",$$PWD)
message ($$CURRENT_DIR)

BUILD_DIR = $$join("Build dir - ",$$OUT_PWD)
message ($$BUILD_DIR)

PRJ_NAME = $$join("Project name - ",$$TARGET)
message ($$PRJ_NAME)
