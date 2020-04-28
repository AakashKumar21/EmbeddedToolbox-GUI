#include "serial.h"
#include <QDebug>

QList<QSerialPortInfo> Serial::m_serialPortList = QSerialPortInfo::availablePorts();
Serial* Serial::_instance = nullptr;


Serial* Serial::getInstance() {
   if (_instance == nullptr)
   {
      _instance = new Serial();
   }
   return(_instance);
}

Serial::Serial(QObject *parent) :
    QObject(parent)
{
    m_findComPort();
}

void Serial::setPort(int port_index)
{
    m_portInfo = Serial::m_serialPortList[port_index];
    qDebug() <<  "Port: " << m_portInfo.portName() << "selected\n";
}

QSerialPort::SerialPortError Serial::Begin(QSerialPort::BaudRate baud)
{
    m_qSerialPort = new QSerialPort(this);
    m_qSerialPort->setPort(m_portInfo);
    m_qSerialPort->setBaudRate(baud);
    m_qSerialPort->setDataBits(QSerialPort::Data8);
    m_qSerialPort->setParity(QSerialPort::NoParity);
    m_qSerialPort->setStopBits(QSerialPort::OneStop);
    m_qSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_qSerialPort->open(QIODevice::ReadWrite);
    return m_qSerialPort->error();
}

void Serial::End()
{
    delete m_qSerialPort;
    m_qSerialPort = nullptr;
}

QStringList Serial::getComPortList()
{
//   auto ports = QSerialPortInfo::availablePorts();
    m_findComPort();
   QStringList portList;
    for(auto x: m_serialPortList)
    {
        portList.append(x.portName());
    }
    return portList;
}

void Serial::m_findComPort()
{
   Serial::m_serialPortList = QSerialPortInfo::availablePorts();
}
