QT += core
QT += testlib
QT -= gui

QMAKE_CXX = clang++
QMAKE_CC = clang

TARGET = ecf

CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11
CONFIG += debug
CONFIG += warn_on

TEMPLATE = app

unix:MOC_DIR = ../tmp
unix:OBJECTS_DIR = ../tmp

SOURCES += main.cpp \
    FilePool.cpp \
    test/TestFilePool.cpp \
    ZippedBuffer.cpp \
    test/TestZippedBuffer.cpp

HEADERS += \
    FilePool.hh \
    test/TestFilePool.hh \
    ZippedBuffer.hh \
    test/TestZippedBuffer.hh

