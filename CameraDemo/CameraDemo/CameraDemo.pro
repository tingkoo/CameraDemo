#-------------------------------------------------
#
# Project created by QtCreator 2018-04-17T08:17:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CameraDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        camdemo.cpp \
    rz_camera.cpp

HEADERS += \
        camdemo.h \
    demodata.h \
    rz_camera.h \
    datatype.h \
    rzapi.h \
    ../../../../Downloads/Demo - x64/RZAPI.H

FORMS += \
        camdemo.ui
