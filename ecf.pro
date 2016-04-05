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
    ZippedBuffer.cpp \
    Zipper.cpp \
    ZippedBufferPool.cpp \
    test/TestFilePool.cpp \
    test/TestZippedBuffer.cpp \
    test/TestZippedBufferPool.cpp \
    test/TestZipper.cpp

HEADERS += \
    FilePool.hh \
    ZippedBuffer.hh \
    Zipper.hh \
    ZippedBufferPool.hh \
    test/TestFilePool.hh \
    test/TestZippedBuffer.hh \
    test/TestZippedBufferPool.hh \
    test/TestZipper.hh

