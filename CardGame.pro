#-------------------------------------------------
#
# Project created by QtCreator 2017-01-26T11:43:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGame
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


SOURCES += main.cpp\
        gameboard.cpp \
     card.cpp \
    pile.cpp \
    cardmove.cpp \
    freecell.cpp \
    game.cpp \
     klondike.cpp \
    rule.cpp \
    spider.cpp \
    pilesubclasses.cpp \
    winningdialog.cpp \
    about.cpp \
    help.cpp

HEADERS  += gameboard.h \
     card.h \
    pile.h \
    cardmove.h \
    freecell.h \
    game.h \
     klondike.h \
    rule.h \
    spider.h \
    pilesubclasses.h \
    winningdialog.h \
    about.h \
    help.h

FORMS    += gameboard.ui \
    winningdialog.ui \
    about.ui \
    help.ui

RESOURCES += \
    cards.qrc
