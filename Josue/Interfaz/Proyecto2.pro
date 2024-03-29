\\\#-------------------------------------------------
#
# Project created by QtCreator 2019-04-16T20:23:41
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    json.cpp \
        main.cpp \
    myplayer.cpp \
    tower.cpp \
    game.cpp \
    client.cpp \
    button.cpp \
    arrow.cpp \
    stadistics.cpp \
    tower2.cpp \
    tower3.cpp \
    arrow2.cpp \
    arrow3.cpp


HEADERS += \
    json.h \
    list.h \
    list_def.h \
    myplayer.h \
    node.h \
    node_def.h \
    tower.h \
    game.h \
    client.h \
    button.h \
    arrow.h \
    stadistics.h \
    tower2.h \
    tower3.h \
    arrow2.h \
    arrow3.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
