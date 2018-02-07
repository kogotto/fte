QT       += testlib

QT       -= gui

DESTDIR = ../bin
TARGET = tst_test

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++14

TEMPLATE = app

INCLUDEPATH += ../


SOURCES += tst_test.cpp \
    test.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test.h
