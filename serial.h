#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>


class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(QObject *parent);
    QSerialPort::SerialPortError sendReset();
    QSerialPort::SerialPortError Write();
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    void setPort(int port_index); // index of QList<QSerialPortInfo>
    QSerialPort::SerialPortError Begin(enum QSerialPort::BaudRate);
    void End();
    static QStringList getComPortList();//CONST // Returns list of COM ports to be added to drop down menu

signals:
//    void NotifyConnected();
//    void NotifyDisconnected();

private slots:
//    void onConnected();
//    void onDisconnected();

private:
    QSerialPortInfo m_portInfo;
    QSerialPort *m_qSerialPort;
    static QList<QSerialPortInfo> m_serialPortList;
    static void m_findComPort();

signals:

};

#endif // SERIAL_H
