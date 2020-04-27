#include "ui_mainview.h"
#include "ui_tab_gpio.h"
#include "View/mainview.h"
#include "View/tab_gpio.h"
#include "View/tab_setup.h"

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto tab_gpio = new TabGpio(this);
    auto tab_setup = new TabSetup(this);
    ui->loTabGpio->addWidget(tab_gpio);
    ui->loSetupTab->addWidget(tab_setup);
}


MainView::~MainView()
{
    delete ui;
}

