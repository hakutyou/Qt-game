#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T10:29:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TD-sirat
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    bullet.cpp \
    enemy.cpp \
    tower/tower.cpp \
    tower/basetower.cpp \
    tower/mystiatower.cpp \
    tower/mystiatowerbuild.cpp \
    tower/basetowerbuild.cpp \
    tower/kaguyatower.cpp \
    tower/kaguyatowerbuild.cpp

HEADERS  += \
    game.h \
    bullet.h \
    enemy.h \
    tower/tower.h \
    tower/basetower.h \
    tower/mystiatower.h \
    tower/mystiatowerbuild.h \
    tower/basetowerbuild.h \
    tower/kaguyatower.h \
    tower/kaguyatowerbuild.h

RESOURCES += \
    res.qrc
