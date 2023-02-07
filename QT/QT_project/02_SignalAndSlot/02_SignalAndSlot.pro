#-------------------------------------------------
#
# Project created by QtCreator 2023-01-10T18:56:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    teacher.cpp \
    student.cpp

HEADERS  += widget.h \
    teacher.h \
    student.h

FORMS    += widget.ui
