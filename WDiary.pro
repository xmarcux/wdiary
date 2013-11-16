#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T11:49:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WDiary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        activity.cpp \
        optionsdialog.cpp \
        exportdialog.cpp \
        treewidgetmenu.cpp \
        edititemdialog.cpp

HEADERS  += mainwindow.h \
            activity.h \
            optionsdialog.h \
            exportdialog.h \
            treewidgetmenu.h \
            edititemdialog.h

CONFIG += C++11
