#ifndef UTILS_H
#define UTILS_H
#include <QObject>

class Utils
{
public:
    Utils();
    static void DestructorMsg(QString &obj);
    static void DestructorMsg(QObject &obj);

};

#endif // UTILS_H
