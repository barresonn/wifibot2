QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    crc.cpp \
    keyreceiver.cpp \
    main.cpp \
    mainwindow.cpp \
    myrobot.cpp

    mainwindow.ui
    myrobot.cpp
    crc.c

HEADERS += \
    crc.h \
    keyreceiver.h \
    mainwindow.h \
    myrobot.h
    crc.h
    myrobot.h
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Wifibot2_fr_MU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
