QT       += core gui serialport
QT_QPA_PLATFORM_PLUGIN_PATH+=C:\Qt\5.12.8\msvc2017\plugins\platforms

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/TabGpio/tabgpiouno.cpp \
    main.cpp \
    View\mainview.cpp \
    View\tab_setup.cpp \
    serial.cpp \
    settings.cpp \
    startup.cpp \
    utils.cpp

HEADERS += \
    View/TabGpio/tabgpiouno.h \
    View\mainview.h \
    View\tab_setup.h \
    serial.h \
    serialcommands.h \
    settings.h \
    startup.h \
    utils.h

FORMS += \
    View/TabGpio/tabgpiouno.ui \
    View\mainview.ui \
    View\tab_setup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
