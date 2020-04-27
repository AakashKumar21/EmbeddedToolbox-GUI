#include "startup.h"

Startup::Startup():
    QObject(nullptr),
    m_tabSetup(new TabSetup(nullptr)),
    m_tabGpio(new TabGpio(nullptr)),
    m_mainView(new MainView(nullptr, *m_tabSetup, *m_tabGpio))
{

}

void Startup::show() const
{
    m_mainView->show();
}
