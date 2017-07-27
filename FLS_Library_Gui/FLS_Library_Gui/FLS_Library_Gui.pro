#-------------------------------------------------
#
# Project created by QtCreator 2017-07-26T11:29:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FLS_Library_Gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inputdialog.cpp \
    outputdialog.cpp \
    ruledialog.cpp \
    inmfsdialog.cpp \
    outmfsdialog.cpp \
    addrulesdialog.cpp

HEADERS  += mainwindow.h \
    inputdialog.h \
    outputdialog.h \
    ruledialog.h \
    inmfsdialog.h \
    outmfsdialog.h \
    addrulesdialog.h

FORMS    += mainwindow.ui \
    inputdialog.ui \
    outputdialog.ui \
    ruledialog.ui \
    inmfsdialog.ui \
    outmfsdialog.ui \
    addrulesdialog.ui
