#include "serial.h"
#include <QDebug>
#include "QmlEngineGlobal.h"
#include "serialcommands.h"

QList<QSerialPortInfo> Serial::m_serialPortList = QSerialPortInfo::availablePorts();
//Serial* Serial::_instance = nullptr;


QSerialPort::SerialPortError Serial::Begin(QSerialPort::BaudRate baud = QSerialPort::Baud115200)
{
    m_qSerialPort->setPort(m_portInfo);
    m_qSerialPort->setBaudRate(baud);
    m_qSerialPort->setDataBits(QSerialPort::Data8);
    m_qSerialPort->setParity(QSerialPort::NoParity);
    m_qSerialPort->setStopBits(QSerialPort::OneStop);
    m_qSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_qSerialPort->open(QIODevice::ReadWrite);

    connect(m_qSerialPort, &QSerialPort::readyRead, this, &Serial::handleReadyRead);

    return m_qSerialPort->error();
}

//Serial* Serial::getInstance() {
//   if (_instance == nullptr)
//   {
//      _instance = new Serial();
//   }
//   return(_instance);
//}

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
    m_qSerialPort = new QSerialPort(this);
    m_findComPort();
    getComPortList();
    m_connected = false;
    m_gpioData.resize(14);
}

QString Serial::getReadouts(int pin) const
{
    return m_gpioData[pin];
}

void Serial::qmlSetOutput(int pin, bool output)
{
    auto _pin = static_cast<Pin>(pin);
    auto _output = static_cast<Output>(output);
    set_digitalWrite(_pin, _output);
}

void Serial::qmlSetPinMode(int pin, bool pinmode)
{
    auto _pin = static_cast<Pin>(pin);
    auto _pinmode = static_cast<PinMode>(pinmode);
    set_pinMode(_pinmode, _pin);
}

QVector<QString> Serial::getReadoutsAll()
{
    return m_gpioData;
}

void Serial::setReadPin(int pin)
{
    m_pinNo = pin;
}


//QStringList Serial::portList()
//{
////    m_portNameList.clear();
////    for(auto &x: m_serialPortList)
////    {
////        m_portNameList.append(x.portName());
////    }
////    return m_portNameList;
//    QStringList x;
//    return x;
//}


void Serial::refreshPortList(bool arg)
{
    m_findComPort();
    qDebug() << "Refresh" << arg;
}

void Serial::onClick(bool arg)
{
    qDebug() << "Clicked: " << arg;
    m_findComPort();
}

bool Serial::isConnected()
{
    qDebug()<< "is conncted:" << m_connected;
    return m_connected;
}

void Serial::Connect(bool arg)
{
    if(arg){
        Begin();
        m_connected = true;
    }
    else {
        End();
        m_connected = false;
    }
    qDebug() << "Connect:" << m_connected;

}

Serial::~Serial()
{
//    if(_instance != nullptr){
//        _instance->End();
//    }
//    delete _instance;
}

void Serial::setPort(int port_index)
{
    m_portInfo = Serial::m_serialPortList[port_index];
    qDebug() <<  "Port: " << m_portInfo.portName() << "selected\n";
}


void Serial::End()
{
    m_qSerialPort->close();
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
    qDebug() << portList;
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

bool Serial::send_Sync()
{
    QByteArray data;
    data.append(static_cast<char>(Cmd::Sync));
    data.append('0');
    data.append('0');
    m_qSerialPort->write(data);
    return 0;
}

QByteArray Serial::getData()
{
    return m_readData;
}

void Serial::test(QString x)
{
    qDebug() << "Test is working" << x;
}

void Serial::refresh()
{
    m_findComPort();
    emit onClickRefresh();
}

void Serial::m_findComPort()
{
    Serial::m_serialPortList = QSerialPortInfo::availablePorts();
}


void Serial::handleReadyRead()
{
    m_readData.clear();
    m_readData = m_qSerialPort->readAll();
    int cmd = m_readData[0];
    int portB = m_readData[1];
    int portD = m_readData[2];

    if(cmd == static_cast<int>(Cmd::DigitalReadouts))
    {

        for(int i=0; i<8; i++)
        {


            // PORTB
            if(portB & (1<<i))
            {
                if(i+8 < 14){
                    m_gpioData[i+8] = "1";
                }
            }
            else
            {
                if(i+8 < 14){
                    m_gpioData[i+8] = "0";
                }
            }

            // PORTD
            if(portD & (1<<i))
            {
              m_gpioData[i] = "1"; // BUG PRONE
            }
            else
            {
                m_gpioData[i] = "0";
            }
        }
    }

    if (!m_timer.isActive())
        m_timer.start(4);
//    qDebug() << "Gpio Data Recv";
//    qDebug() <<  m_gpioData;
}

