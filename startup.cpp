#include "startup.h"
#include <QDebug>

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

Startup::~Startup()
{
    delete &m_mainView;
//    m_mainView->~MainView();
}
