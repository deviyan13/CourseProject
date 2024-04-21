QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bigltypefigure.cpp \
    dialogaboutgame.cpp \
    dialogchoosinggamestart.cpp \
    figureitem.cpp \
    gamefield.cpp \
    inverseltypefigure.cpp \
    inversestypefigure.cpp \
    ltypefigure.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    miniltypefigure.cpp \
    square2typefigure.cpp \
    stick4typefigure.cpp \
    stypefigure.cpp \
    ttypefigure.cpp \
    typesoffigures.cpp

HEADERS += \
    bigltypefigure.h \
    dialogaboutgame.h \
    dialogchoosinggamestart.h \
    figureitem.h \
    gamefield.h \
    inverseltypefigure.h \
    inversestypefigure.h \
    ltypefigure.h \
    mainmenu.h \
    mainwindow.h \
    miniltypefigure.h \
    square2typefigure.h \
    stick4typefigure.h \
    stypefigure.h \
    ttypefigure.h \
    typesoffigures.h

FORMS += \
    dialogaboutgame.ui \
    dialogchoosinggamestart.ui \
    mainmenu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
