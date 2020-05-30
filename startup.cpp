#include <QQmlApplicationEngine>
#include "startup.h"

Startup::Startup(void)
{
    qmlRegisterType<Serial>("com.Serial",1,0,"Serial");
}

