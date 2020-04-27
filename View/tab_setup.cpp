#include "tab_setup.h"
#include "ui_tab_setup.h"

#include <QSerialPortInfo>
#include <QDebug>
#include <iostream>
#include <QSerialPort>
#include <QDebug>
#include <Windows.h>
#include <QElapsedTimer>
#include "utils.h"
#include "serial.h"


TabSetup::TabSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab_setup)
{
    ui->setupUi(this);
}

TabSetup::~TabSetup()
{
    Utils::DestructorMsg(*this);
    delete ui;
}

void TabSetup::on_btn_refresh_port_clicked()
{
    ui->comPortSelect->clear();
    ui->comPortSelect->addItems(Serial::getComPortList());
    ui->comPortSelect->showPopup();
}
