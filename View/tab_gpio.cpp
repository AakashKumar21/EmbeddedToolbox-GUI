#include "tab_gpio.h"
#include "ui_tab_gpio.h"
#include <QDebug>
#include "utils.h"

TabGpio::TabGpio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab_gpio),
    m_serialConn(*Serial::getInstance())
{
    ui->setupUi(this);
}

TabGpio::~TabGpio()
{
    Utils::DestructorMsg(*this);
    delete ui;
}

void TabGpio::on_pinMode_0_stateChanged(int x)
{
    if(x == 1){
        ui->pinMode_0->setText("HIGH");

    }
    else{
        ui->pinMode_0->setText("LOW");
    }
}


void TabGpio::on_output_0_stateChanged(int x)
{

}
