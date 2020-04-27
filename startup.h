#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "View/mainview.h"
#include "View/tab_gpio.h"
#include "View/tab_setup.h"
#include "utils.h"

class Startup final: public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;
    ~Startup();

private:
    TabSetup *m_tabSetup;
    TabGpio *m_tabGpio;
    MainView *m_mainView;
    QJsonObject GetJsonObject(const QString& rawJson);

    explicit Startup(const Startup& rhs) = delete;
    Startup& operator=(const Startup& rhs) = delete;

signals:

};

#endif // STARTUP_H
