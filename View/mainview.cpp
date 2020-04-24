#include "mainview.h"
#include "ui_mainview.h"
#include "View/tab_gpio.h"
#include <QSerialPortInfo>
#include <QDebug>

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto tab_gpio = new TabGpio(this);
    ui->loTabGpio->addWidget(tab_gpio);
    QList<QSerialPortInfo> x = QSerialPortInfo::availablePorts();
    qWarning() << "No. of ports :" << x.size();

    QStringList ports;
    for(auto y: x)
    {
        ports.append(y.portName());
    }
    ui->comPortSelect->addItems(ports);
    if(x.size() >= 1)
    {
        for(auto y: x)
        {
            qWarning() << y.serialNumber() << ' ';
            qWarning() << y.portName() << y.systemLocation();
        }
    }
}

MainView::~MainView()
{
    delete ui;
}

