#!/bin/sh

qmake -project "QT += testlib" "CONFIG += C++11" "QMAKE_CXX = clang++" "QMAKE_CC = clang"
