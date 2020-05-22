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

    Q_PROPERTY(QStringList portList READ getComPortList NOTIFY onClickRefresh)
    Q_PROPERTY(bool clicked WRITE onClick)
    Q_PROPERTY(bool comPort WRITE setPort)
//    Q_PROPERTY(bool connectSerial WRITE Begin)

//    Q_PROPERTY(QString pin_no WRITE setId)

public:

    explicit Serial(QObject *parent = nullptr);
    ~Serial();
    bool Write(QByteArray);
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    void setPort(int port_index); // index of QList<QSerialPortInfo>
    QSerialPort::SerialPortError Begin(enum QSerialPort::BaudRate);
    void End();
    // Setters
    bool set_pinMode(PinMode pinmode,Pin pin);
    bool set_digitalWrite(Pin pin, Output output) ;
    bool set_analogWrite(Pin pin, int duty) ;
    bool set_digitalRead(Pin pin) ;
    bool set_AnalogRead(MUX pin) ;
    bool set_AnalogConfig(AdcPrescale divider, AdcVRef ref, AdcBits accuracy) ;
    bool send_Sync();
    QByteArray getData();

public slots:
    void test(QString x);
    // Refresh ComPortList
    void refresh();
    //Returns List of COM ports to be added to drop down menu
    QStringList getComPortList();

signals:
//    void NotifyConnected();
//    void NotifyDisconnected();
    void onClickRefresh();

private slots:
//    void onConnected();
//    void onDisconnected();

private:
//    static Serial* _instance;

//    Serial(const Serial&);
//    Serial& operator=(const Serial&);

    QStringList portList();
    void refreshPortList(bool arg);
    void onClick(bool arg);

    QSerialPortInfo m_portInfo;
    QSerialPort *m_qSerialPort;
    static QList<QSerialPortInfo> m_serialPortList;
    static void m_findComPort();

    QByteArray m_readData;
    QTimer m_timer;
    QStringList m_portNameList;

signals:
    void NotifyData();

private slots:
    void handleReadyRead();
//    void handleTimeout();
//    void handleError(QSerialPort::SerialPortError error);

signals:

};

#endif // SERIAL_H
