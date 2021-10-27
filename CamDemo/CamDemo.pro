#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T17:52:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    Camera/Include/DataType.h \
    camera.h \
    Camera/Include/RZAPI.H

FORMS    += mainwindow.ui

LIBS    += "C:\Users\Ada\Desktop\CamDemo\RZCamAPI.lib"

RESOURCES += \
    resources.qrc
