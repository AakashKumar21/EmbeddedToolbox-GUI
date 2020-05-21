#include "View/mainview.h"
#include <utils.h>


MainView::MainView(QObject *parent, TabSetup &setup, TabGpioUno &gpio_uno, TabAdcUno &adc_uno)
    : QObject(parent),
      m_tabSetup(setup),
      m_tabGpioUno(gpio_uno),
      m_tabAdcUno(adc_uno)
{
//    ui->setupUi(this);
    m_tabSetup.setParent(this);
    m_tabGpioUno.setParent(this);
    m_tabAdcUno.setParent(this);
//    ui->loTabGpio->addWidget(&m_tabGpioUno);
//    ui->loAdcTab->addWidget(&m_tabAdcUno);
//    ui->loSetupTab->addWidget(&m_tabSetup);
}


MainView::~MainView()
{
    Utils::DestructorMsg(*this);
//    delete ui;
}

