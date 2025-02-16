QT       += core gui sql widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = test_exam
TEMPLATE = app
CONFIG += console

SOURCES += main.cpp \
    createroutewindow.cpp \
    databasemanager.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    profilewindow.cpp \
    registerwindow.cpp \
    usermanager.cpp

HEADERS += databasemanager.h \
    createroutewindow.h \
    loginwindow.h \
    mainwindow.h \
    profilewindow.h \
    registerwindow.h \
    usermanager.h

FORMS += login_window.ui register_window.ui mainwindow.ui route_card_window.ui create_route_window.ui profile_window.ui
QT       += core gui sql widgets


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

