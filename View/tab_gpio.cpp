#include "tab_gpio.h"
#include "ui_tab_gpio.h"
#include <QDebug>
#include "utils.h"

TabGpio::TabGpio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab_gpio)
{

}

TabGpio::~TabGpio()
{
    Utils::DestructorMsg(*this);
    delete ui;
}
