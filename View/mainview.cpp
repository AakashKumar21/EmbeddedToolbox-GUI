#include "View/mainview.h"
#include <utils.h>

MainView::MainView(QWidget *parent, TabSetup &setup, TabGpioUno &gpio_uno)
    : QMainWindow(parent),
      ui(new Ui::MainView),
      m_tabSetup(setup),
      m_tabGpioUno(gpio_uno)
{
    ui->setupUi(this);
    m_tabSetup.setParent(this);
    m_tabGpioUno.setParent(this);
    ui->loSetupTab->addWidget(&m_tabSetup);
    ui->loTabGpio->addWidget(&m_tabGpioUno);
}


MainView::~MainView()
{
    Utils::DestructorMsg(*this);
    delete ui;
}

