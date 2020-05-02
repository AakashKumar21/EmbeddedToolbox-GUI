#include "tab_setup.h"
#include "ui_tab_setup.h"
#include "utils.h"
#include "serial.h"

#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>


TabSetup::TabSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab_setup),
    m_serialConn(*Serial::getInstance())
{
    ui->setupUi(this);
    ui->btn_disconnect->setDisabled(true);
}

TabSetup::~TabSetup()
{
    Utils::DestructorMsg(*this);
    delete ui;
}

void TabSetup::on_btn_refresh_port_clicked()
{
    ui->dropdown_comPortSelect->clear();
    ui->dropdown_comPortSelect->addItems(Serial::getComPortList());
    ui->dropdown_comPortSelect->showPopup();
    qDebug() << "Refresh btn clicked\n";
}

void TabSetup::on_dropdown_comPortSelect_activated(int index)
{
    qDebug() << "Index: " << index << "selected from drop down ";
    m_serialConn.setPort(index);
}

void TabSetup::on_btn_connect_clicked()
{
    qDebug() << "Connnecting";
    auto err = m_serialConn.Begin(QSerialPort::Baud115200); // Connection begins
    if(err == 0)
    {
        qDebug() << "Connection Success\n";
        ui->btn_connect->setDisabled(true);
        ui->btn_disconnect->setEnabled(true);
    }
    else qDebug() << "Error: " << err << "While Opening Port";
}

void TabSetup::on_btn_disconnect_clicked()
{
    qDebug() << "Closing Port";
    m_serialConn.End();
    ui->btn_connect->setEnabled(true);
    ui->btn_disconnect->setDisabled(true);
}
