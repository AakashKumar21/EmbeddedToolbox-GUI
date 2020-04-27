#include "serial.h"
#include <QDebug>

Serial::Serial(QObject *parent, QSerialPortInfo &port_info) :
    QObject(parent),
    m_portInfo(port_info)
{

}

QStringList Serial::getComPortList()
{
   auto ports = QSerialPortInfo::availablePorts();

   QStringList portList;
    for(auto x: ports)
    {
        portList.append(x.portName());
    }
    return portList;
}

void Serial::m_findComPorts()
{
//    auto ports = QSerialPortInfo::availablePorts();

//     for(auto x: portList)
//     {
//         portList.append(x);
//     }
}
