#include "tab_setup.h"
#include "ui_tab_setup.h"

#include <QSerialPortInfo>
#include <QDebug>
#include <iostream>
#include <QSerialPort>
#include <QDebug>
#include <Windows.h>
#include <QElapsedTimer>


TabSetup::TabSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab_setup)
{
    ui->setupUi(this);
    auto m_ports = QSerialPortInfo::availablePorts();
    QSerialPort serial;
    QElapsedTimer timer;

    QStringList ports;
    for(auto &y: m_ports)
    {
        ui->comPortSelect->addItem(y.portName());
    }
}

TabSetup::~TabSetup()
{
    delete ui;
}
