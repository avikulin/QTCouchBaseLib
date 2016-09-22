TEMPLATE = subdirs
CONFIG += c++11
SUBDIRS += \
    CouchBaseAdapter \
    CouchBaseUtils\
    DataLayer \
    MainApp \
    CouchBaseTester
 # mapping the subdirs and folders
    CouchBaseAdapter.subdir = CouchBaseAdapter
    CouchBaseUtils.subdir = CouchBaseUtils
    DataLayer.subdir = DataLayer
    MainApp.subdir = MainApp
    CouchBaseTester.subdir = CouchBaseTester
 # managing dependencies
    CouchBaseTester.depends = CouchBaseAdapter
    CouchBaseAdapter.depends = CouchBaseUtils

