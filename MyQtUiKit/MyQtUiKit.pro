#-------------------------------------------------
#
# Project created by QtCreator 2018-01-20T09:03:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQtUiKit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    THUiKit/THUiToast.cpp \
    THUiKit/THUiAbstractProgress.cpp \
    THUiKit/THUiHorizontalProgress.cpp \
    THUiKit/THUiVerticalProgress.cpp \
    THUiKit/THUiVerticalProgressExt.cpp \
    THUiKit/THUiAbstractProgressExt.cpp \
    THUiKit/THUiHorizontalProgressExt.cpp \
    THUiKit/THUiGroupWidget.cpp \
    THUiKit/THUiPageControl.cpp \
    THUiKit/THUiLabel.cpp \
    THUiKit/AnimationStackedWidget.cpp \
    THUiKit/THUiHeartBeatView.cpp \
    test1.cpp \
    test2.cpp

HEADERS  += mainwindow.h \
    THUiKit/THUiToast.h \
    THUiKit/THUiAbstractProgress.h \
    THUiKit/THUiHorizontalProgress.h \
    THUiKit/THUiVerticalProgress.h \
    THUiKit/THUiVerticalProgressExt.h \
    THUiKit/THUiAbstractProgressExt.h \
    THUiKit/THUiHorizontalProgressExt.h \
    THUiKit/THUiGroupWidget.h \
    THUiKit/THUiPageControl.h \
    THUiKit/THUiLabel.h \
    THUiKit/AnimationStackedWidget.h \
    THUiKit/THUiHeartBeatView.h \
    test1.h \
    test2.h

FORMS    += mainwindow.ui \
    test1.ui \
    test2.ui

include(libs/qBreakpad/qBreakpad.pri)
#QMAKE_LIBDIR += $$OUT_PWD/libs/qBreakpad/handler
#LIBS += -lqBreakpad
#LIBS += \
#    -LF:/all_work/qt/MyQtUiKit/MyQtUiKit/libs/qBreakpad/handler -lqBreakpad
#

QMAKE_LIBDIR += $$PWD/libs/qBreakpad/handler
LIBS += -lqBreakpad
