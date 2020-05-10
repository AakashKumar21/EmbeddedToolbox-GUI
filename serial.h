#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>
#include "serialcommands.h"
#include <QVector>

// This in singleton class
class Serial : public QObject
{
    Q_OBJECT
public:

    static Serial* getInstance();
    bool Write(QByteArray);
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    void setPort(int port_index); // index of QList<QSerialPortInfo>
    QSerialPort::SerialPortError Begin(enum QSerialPort::BaudRate);
    void End();
    static QStringList getComPortList();//CONST // Returns list of COM ports to be added to drop down menu
    // Setters
    bool set_pinMode(PinMode pinmode,Pin pin);
    bool set_digitalWrite(Pin pin, Output output) ;
    bool set_analogWrite(Pin pin, int duty) ;
    bool set_digitalRead(Pin pin) ;
    bool set_AnalogRead(MUX pin) ;
    bool set_AnalogConfig(AdcPrescale divider, AdcVRef ref, AdcBits accuracy) ;
    bool send_Sync();
    QByteArray getData();

signals:
//    void NotifyConnected();
//    void NotifyDisconnected();

private slots:
//    void onConnected();
//    void onDisconnected();

private:
    static Serial* _instance;
    explicit Serial(QObject *parent = nullptr);
    Serial(const Serial&);
    Serial& operator=(const Serial&);
    ~Serial();

    QSerialPortInfo m_portInfo;
    QSerialPort *m_qSerialPort;
    static QList<QSerialPortInfo> m_serialPortList;
    static void m_findComPort();

    QByteArray m_readData;
    QTimer m_timer;

signals:
    void NotifyData();

private slots:
    void handleReadyRead();
//    void handleTimeout();
//    void handleError(QSerialPort::SerialPortError error);

signals:

};

#endif // SERIAL_H
