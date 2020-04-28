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

void Serial::Write(char cmd)
{

}

void Serial::Write(char cmd, char ins)
{
    qDebug() << "Going to write " << static_cast<int>(cmd) <<' ' << static_cast<int>(ins) << '\n';
    if(m_qSerialPort->isWritable())
    {
        qDebug() << "Port Open, Writing\n";
        QByteArray arr;
        arr.append(cmd); arr.append(ins);
        m_qSerialPort->write(arr);
        if(m_qSerialPort->error() == 0)
        {
            qDebug() << "Success\n";
        }
        else
        {
            qDebug() << m_qSerialPort->error();
        }
    }
}


Serial::Serial(QObject *parent) :
    QObject(parent)
{
    m_findComPort();
}

Serial::~Serial()
{
    if(_instance != nullptr){
        _instance->End();
    }
    delete _instance;
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
