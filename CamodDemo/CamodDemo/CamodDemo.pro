#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T14:41:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamodDemo
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
        camod.cpp \
    formcameralist.cpp \
    formcapresolution.cpp \
    formbitdepth.cpp \
    formcoloradjust.cpp \
    formexposure.cpp \
    formwhitebalance.cpp \
    qspecialbtn.cpp \
    formcolorgray.cpp \
    formcooling.cpp \
    formdarkfield.cpp \
    formflip.cpp \
    formframerate.cpp \
    formhistogram.cpp \
    formmisc.cpp \
    formparameters.cpp \
    formpowerfreq.cpp \
    formroi.cpp \
    formsampling.cpp

HEADERS += \
        camod.h \
    formcameralist.h \
    formcapresolution.h \
    formbitdepth.h \
    formcoloradjust.h \
    formexposure.h \
    formwhitebalance.h \
    qspecialbtn.h \
    formcolorgray.h \
    formcooling.h \
    formdarkfield.h \
    formflip.h \
    formframerate.h \
    formhistogram.h \
    formmisc.h \
    formparameters.h \
    formpowerfreq.h \
    formroi.h \
    formsampling.h

FORMS += \
        camod.ui \
    formcameralist.ui \
    formcapresolution.ui \
    formbitdepth.ui \
    formwhitebalance.ui \
    formexposure.ui \
    formcoloradjust.ui \
    formframerate.ui \
    formpowerfreq.ui \
    formcolorgray.ui \
    formflip.ui \
    formsampling.ui \
    formroi.ui \
    formhistogram.ui \
    formdarkfield.ui \
    formcooling.ui \
    formmisc.ui \
    formparameters.ui

RESOURCES += \
    resources.qrc
