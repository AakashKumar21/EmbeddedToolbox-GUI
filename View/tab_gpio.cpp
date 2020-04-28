#include "tab_gpio.h"
#include "ui_tab_gpio.h"
#include <QDebug>
#include "utils.h"
#include "serialcommands.h"

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
    _managePinModeText(*ui->pinMode_0,(bool)x);
}


void TabGpio::on_output_0_stateChanged(int x)
{
    if(x == 1){
        m_serialConn.Write(Inst::PinHigh, Inst::D0);
    }
    else{
        m_serialConn.Write(Inst::PinLow, Inst::D0);
    }
    _manageOutputText(*ui->output_0, x);
}

void TabGpio::_managePinModeText(QCheckBox& box, bool x)
{
    if(x){
        box.setText("OUTPUT");

    }
    else{
        box.setText("INPUT");
    }
}

void TabGpio::_manageOutputText(QCheckBox& box, bool x)
{
    if(x){
        box.setText("HIGH");

    }
    else{
        box.setText("LOW");
    }
}
