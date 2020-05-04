#include <QApplication>
#include "startup.h"
#include <QtPlugin>
#include <QDebug>

int main(int argc, char *argv[])
{
//    QCoreApplication::addLibraryPath("C:/Qt/5.12.8/msvc2017/plugins");
//    QCoreApplication::addLibraryPath(".");
    auto lst=QCoreApplication::libraryPaths();
    qDebug() << lst;
    QApplication a(argc, argv);
    Startup w;
    w.show();
    return a.exec();
}
