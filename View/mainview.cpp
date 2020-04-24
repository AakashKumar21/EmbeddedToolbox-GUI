#include "ui_mainview.h"
#include "ui_tab_gpio.h"
#include "View/mainview.h"
#include "View/tab_gpio.h"


MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto tab_gpio = new TabGpio(this);
    ui->loTabGpio->addWidget(tab_gpio);
}

MainView::~MainView()
{
    delete ui;
}

