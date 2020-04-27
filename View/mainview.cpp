#include "View/mainview.h"
#include <utils.h>
// BUG : IDK WHY DESTRUCTOR IS NOT CALLING AS THE FUNC "DestructorMsg" IS NOT EXECUTING

MainView::MainView(QWidget *parent, TabSetup &setup, TabGpio &gpio)
    : QMainWindow(parent),
      ui(new Ui::MainView),
      m_tabSetup(setup),
      m_tabGpio(gpio)
{
    ui->setupUi(this);
    m_tabSetup.setParent(this);
    m_tabGpio.setParent(this);
//    auto tab_gpio = new TabGpio(this);
//    auto tab_setup = new TabSetup(this);
    ui->loTabGpio->addWidget(&m_tabGpio);
    ui->loSetupTab->addWidget(&m_tabSetup);
}


MainView::~MainView()
{
    Utils::DestructorMsg(*this);
    delete ui;
}

