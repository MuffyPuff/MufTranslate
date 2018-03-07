#-------------------------------------------------
#
# Project created by QtCreator 2017-12-30T23:52:38
#
#-------------------------------------------------

QT       += core gui widgets

DESTDIR = ../../bin

TARGET = MufTranslate
TEMPLATE = lib

SOURCES += \
        src/muftranslate.cpp

HEADERS += \
        src/muftranslate.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
