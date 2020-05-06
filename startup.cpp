#include "startup.h"
#include <QDebug>

Startup::Startup():
    QObject(nullptr),
    m_tabSetup(new TabSetup(nullptr)),
    m_tabGpioUno(new TabGpioUno(nullptr)),
    m_tabAdcUno(new TabAdcUno(nullptr)),
    m_mainView(new MainView(nullptr, *m_tabSetup,*m_tabGpioUno, *m_tabAdcUno))
{
}

void Startup::show() const
{
    m_mainView->show();
}


Startup::~Startup()
{
    Utils::DestructorMsg(*this);
    m_mainView->~MainView();
}
