#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "serial.h"

class Startup final: public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;
//    ~Startup();

private:
//    TabSetup *m_tabSetup;
//    TabGpioUno *m_tabGpioUno;
//    TabAdcUno *m_tabAdcUno;
//    MainView *m_mainView;
    Serial *m_serial;

    QJsonObject GetJsonObject(const QString& rawJson);

    explicit Startup(const Startup& rhs) = delete;
    Startup& operator=(const Startup& rhs) = delete;

signals:

};

#endif // STARTUP_H
