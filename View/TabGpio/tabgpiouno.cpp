#include "tabgpiouno.h"
#include "ui_tabgpiouno.h"

TabGpioUno::TabGpioUno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabGpioUno)
{
    ui->setupUi(this);
}

TabGpioUno::~TabGpioUno()
{
    delete ui;
}
