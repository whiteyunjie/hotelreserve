#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T15:26:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelReservation
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    cuslog.cpp \
    cusreg.cpp \
    hotlog.cpp \
    hotreg.cpp \
    customers.cpp \
    hotels.cpp \
    guestroom.cpp \
    orders.cpp \
    hotelmanager.cpp \
    manipulatesql.cpp \
    manipulate3.cpp \
    platform.cpp \
    platformlog.cpp \
    hotelwindow.cpp \
    hotupdate.cpp \
    platwindow.cpp \
    manipulate4.cpp \
    roominformation.cpp \
    manipulate2.cpp \
    hotelreserve.cpp \
    orderscus.cpp \
    hoteldetails.cpp \
    trade.cpp \
    cuschangeinfo.cpp \
    assess.cpp \
    hotelgovern.cpp \
    manipulate5.cpp \
    addman.cpp \
    managers.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    cuslog.h \
    cusreg.h \
    hotlog.h \
    hotreg.h \
    manipulatesql.h \
    customers.h \
    hotels.h \
    guestroom.h \
    cusread.h \
    orders.h \
    manipulate2.h \
    manipulate3.h \
    hotelmanager.h \
    platform.h \
    platformlog.h \
    hotupdate.h \
    manipulate4.h \
    roominformation.h \
    platwindow.h \
    hotelwindow.h \
    hotelreserve.h \
    orderscus.h \
    hoteldetails.h \
    trade.h \
    cuschangeinfo.h \
    assess.h \
    hotelgovern.h \
    manipulate5.h \
    addman.h \
    managers.h

FORMS += \
        mainwindow.ui \
    login.ui \
    cuslog.ui \
    cusreg.ui \
    hotlog.ui \
    hotreg.ui \
    platform.ui \
    hotelwindow.ui \
    hotupdate.ui \
    platwindow.ui \
    roominformation.ui \
    hotelreserve.ui \
    orderscus.ui \
    hoteldetails.ui \
    trade.ui \
    cuschangeinfo.ui \
    assess.ui \
    addman.ui \
    decreaseman.ui \
    managers.ui

RESOURCES += \
    myicon.qrc \
    qssapp.qrc \
    background.qrc
