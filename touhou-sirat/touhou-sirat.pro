#-------------------------------------------------
#
# Project created by QtCreator 2016-07-10T20:44:08
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = touhou-sirat
TEMPLATE = app


SOURCES += main.cpp \
    mainrect.cpp \
    Weapon/bullet.cpp \
    enemy.cpp \
    game.cpp \
    Value/score.cpp \
    Value/rolestate.cpp

HEADERS  += \
    mainrect.h \
    Weapon/bullet.h \
    enemy.h \
    game.h \
    Value/score.h \
    Value/rolestate.h

RESOURCES += \
    res.qrc
