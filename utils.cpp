#include "utils.h"
#include <QDebug>

Utils::Utils()
{
}

void Utils::DestructorMsg(QObject &obj)
{
    qWarning() << "Object" << obj.metaObject()->className() << "Destroyed\n";
}

void Utils::DestructorMsg(QString &obj)
{
    qWarning() << "Object" << obj << "Destroyed\n";
}
