#-------------------------------------------------
#
# Project created by QtCreator 2018-05-01T15:14:12
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NDVICalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    newcolorbar.png

DEFINES  += "LARGEADDRESSAWARE"
