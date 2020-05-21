#include "startup.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>
#include "View/TabGpio/tabgpiouno.h"
#include "serial.h"

Startup::Startup(void)
{
    qmlRegisterType<TabGpioUno>("com.tabGpioUno",1,0,"TabGpioUno");
    qmlRegisterType<Serial>("com.Serial",1,0,"Serial");
//    m_serial = Serial::getInstance();
}

