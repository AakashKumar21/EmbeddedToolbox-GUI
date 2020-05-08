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

bool Serial::Write(QByteArray data)
{
    qDebug() << "Writing:";
    for(auto &t: data)
    {
        qDebug() << static_cast<int>(t) << ' ';
    }

    if(m_qSerialPort->isWritable())
    {
        qDebug() << "Port Open, Writing\n";

        m_qSerialPort->write(data);

        if(m_qSerialPort->error() == 0)
        {
            qDebug() << "Success\n";
            return 0;
        }
        else
        {
            qDebug() << m_qSerialPort->error();
            return 1;
        }
    }
    return 1;
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

bool Serial::set_pinMode(PinMode pinMode, Pin pin)
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::PinMode));
    data.append(static_cast<char>(pinMode));
    data.append(static_cast<char>(pin));

    return this->Write(data);
}

bool Serial::set_digitalWrite(Pin pin, Output output)
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::DigitalWrite));
    data.append(static_cast<char>(pin));
    data.append(static_cast<char>(output));

    return this->Write(data);
}

bool Serial::set_analogWrite(Pin pin, int duty)
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::AnalogWrite));
    data.append(static_cast<char>(pin));
    data.append(static_cast<char>(duty));

    return this->Write(data);
}

bool Serial::set_digitalRead(Pin pin)
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::DigitalRead));
    data.append(static_cast<char>(pin));

    return this->Write(data);
}

bool Serial::set_AnalogRead(MUX pin)
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::AnalogRead));
    data.append(static_cast<char>(pin));

    return this->Write(data);
}

bool Serial::set_AnalogConfig(AdcPrescale divider, AdcVRef ref, AdcBits accuracy)
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::AnalogConfig));
    data.append(static_cast<char>(divider));
    data.append(static_cast<char>(ref));
    data.append(static_cast<char>(accuracy));

    return this->Write(data);
}

void Serial::m_findComPort()
{
   Serial::m_serialPortList = QSerialPortInfo::availablePorts();
}
