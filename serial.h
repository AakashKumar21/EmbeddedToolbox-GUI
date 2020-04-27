#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>


class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(QObject *parent, QSerialPortInfo &port_info);
    QSerialPort::SerialPortError sendReset();
    QSerialPort::SerialPortError Write();
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    static QStringList getComPortList(); // Returns list of COM ports to be added to drop down menu


signals:
//    void NotifyConnected();
//    void NotifyDisconnected();

private slots:
//    void onConnected();
//    void onDisconnected();

private:
    QSerialPortInfo &m_portInfo;
    void m_findComPorts();

signals:

};

#endif // SERIAL_H
