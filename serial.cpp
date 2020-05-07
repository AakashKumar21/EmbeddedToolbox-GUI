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

int Serial::Write(char cmd, char ins)  // 0: success , 1:fail
{
    qDebug() << "Going to write " << QString::number(cmd)  <<' ' << QString::number(ins) << '\n';
    if(m_qSerialPort->isWritable())
    {
        qDebug() << "Port Open, Writing\n";
        QByteArray arr;
        arr.append(cmd); arr.append(ins);
        m_qSerialPort->write(arr);
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

int Serial::Write(char cmd, char a, char b)
{
    qDebug() << "Going to write "
             << QString::number(cmd)
             <<' '
             << QString::number(a)
             << ' '
             << QString::number(b);

    if(m_qSerialPort->isWritable())
    {
        qDebug() << "Port Open, Writing\n";
        QByteArray arr;
        arr.append(cmd);
        arr.append(a);
        arr.append(b);
        m_qSerialPort->write(arr);

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

bool Serial::Write(QByteArray data)
{
    for(auto &t: data)
    {
        qDebug() << t << ' ';
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

bool Serial::set_pinMode(Cmd cmd, PinMode pinMode, Pin pin)
{
    QByteArray data;
    data.append(static_cast<char>(cmd));
    data.append(static_cast<char>(pinMode));
    data.append(static_cast<char>(pin));

    return this->Write(data);
}

bool Serial::set_digitalWrite(Cmd cmd, Pin pin, Output output)
{
    QByteArray data;
    data.append(static_cast<char>(cmd));
    data.append(static_cast<char>(pin));
    data.append(static_cast<char>(output));

    return this->Write(data);
}

bool Serial::set_analogWrite(Cmd cmd, Pin pin, int duty)
{
    QByteArray data;
    data.append(static_cast<char>(cmd));
    data.append(static_cast<char>(pin));
    data.append(static_cast<char>(duty));

    return this->Write(data);
}

bool Serial::set_digitalRead(Cmd cmd, Pin pin)
{
    QByteArray data;
    data.append(static_cast<char>(cmd));
    data.append(static_cast<char>(pin));

    return this->Write(data);
}

bool Serial::set_AnalogRead(Cmd cmd, MUX pin)
{
    QByteArray data;
    data.append(static_cast<char>(cmd));
    data.append(static_cast<char>(pin));

    return this->Write(data);
}

bool Serial::set_AnalogConfig(Cmd cmd, AdcPrescale divider, AdcVRef ref, AdcBits accuracy)
{
    QByteArray data;
    data.append(static_cast<char>(cmd));
    data.append(static_cast<char>(divider));
    data.append(static_cast<char>(ref));
    data.append(static_cast<char>(accuracy));

    return this->Write(data);
}

void Serial::m_findComPort()
{
   Serial::m_serialPortList = QSerialPortInfo::availablePorts();
}
