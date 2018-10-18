#-------------------------------------------------
#
# Project created by QtCreator 2017-09-18T13:11:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtxiagao
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        choicepage.cpp \
    login.cpp \
    signup.cpp \
    BasicInfo.cpp \
    Quas.cpp \
    Answ.cpp \
    user.cpp \
    userlist.cpp \
    Anslist.cpp \
    answer.cpp \
    total.cpp \
    focus.cpp \
    searchq.cpp

HEADERS += \
        choicepage.h \
    login.h \
    signup.h \
    BasicInfo.h \
    Quas.h \
    Answ.h \
    user.h \
    userlist.h \
    Anslist.h \
    answer.h \
    total.h \
    focus.h \
    searchq.h

FORMS += \
        choicepage.ui \
    login.ui \
    signup.ui \
    answer.ui \
    focus.ui \
    searchq.ui

RESOURCES += \
    menu.qrc
