QT += core
QT -= gui

TARGET = DataBase
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    record.cpp \
    field.cpp

HEADERS += \
    data.h \
    record.h \
    field.h

