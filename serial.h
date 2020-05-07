#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "serialcommands.h"

// This in singleton class
class Serial : public QObject
{
    Q_OBJECT
public:

    static Serial* getInstance();

    QSerialPort::SerialPortError sendReset();
    int Write(char cmd);
    int Write(char cmd, char ins);
    int Write(char cmd, char a, char b);
    bool Write(QByteArray);
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    void setPort(int port_index); // index of QList<QSerialPortInfo>
    QSerialPort::SerialPortError Begin(enum QSerialPort::BaudRate);
    void End();
    static QStringList getComPortList();//CONST // Returns list of COM ports to be added to drop down menu
    // Setters
    bool set_pinMode(Cmd cmd,PinMode pinmode,Pin pin);
    bool set_digitalWrite(Cmd cmd, Pin pin, Output output) ;
    bool set_analogWrite(Cmd cmd, Pin pin, int duty) ;
    bool set_digitalRead(Cmd cmd, Pin pin) ;
    bool set_AnalogRead(Cmd cmd,MUX pin) ;
    bool set_AnalogConfig(Cmd cmd, AdcPrescale divider, AdcVRef ref, AdcBits accuracy) ;

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

signals:

};

#endif // SERIAL_H
