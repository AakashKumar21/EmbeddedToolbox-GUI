#include "tab_gpio.h"
#include "ui_tab_gpio.h"
#include <QDebug>

TabGpio::TabGpio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab_gpio)
{

}

TabGpio::~TabGpio()
{
    delete ui;
}
