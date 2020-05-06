#include "tabadcuno.h"
#include "ui_tabadcuno.h"

TabAdcUno::TabAdcUno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabAdcUno)
{
    ui->setupUi(this);
}

TabAdcUno::~TabAdcUno()
{
    delete ui;
}
