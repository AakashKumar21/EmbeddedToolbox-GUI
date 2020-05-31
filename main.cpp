#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>

#include "startup.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    Startup w;

//    QQuickStyle::setStyle("Material");

//    QQuickView view;
//    view.setSource(QUrl("qrc:/main.qml"));
//    view.show();
//    QQuickItem *object = view.rootObject();

//    QQmlEngine engine;
//    QQmlComponent component(&engine,
//            QUrl("qrc:/main.qml"));
//    QObject *object = component.create();

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
