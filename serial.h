#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>
#include <QVector>
#include <QArrayData>
#include "serialcommands.h"

class Serial : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList portList READ getComPortList NOTIFY onClickRefresh)
//    Q_PROPERTY(bool clicked WRITE onClick)
    Q_PROPERTY(bool comPort WRITE setPort)

    Q_PROPERTY(bool connected READ isConnected WRITE Connect)
    Q_PROPERTY(int port WRITE setPort)
//    Q_PROPERTY(int pin_readout READ getReadouts WRITE setReadPin NOTIFY onGpioDataRecv)
//    Q_PROPERTY(QString readouts READ getReadouts WRITE readoutPin NOTIFY onGpioDataRecv)

public:

    explicit Serial(QObject *parent = nullptr);
    ~Serial();
    bool Write(QByteArray);
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    void setPort(int port_index = 0 ); // index of QList<QSerialPortInfo>
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

Q_INVOKABLE QVector<QString> getReadoutsAll();

signals:
    void NotifyData();
    //    void NotifyConnected();
    //    void NotifyDisconnected();
    void onClickRefresh();
    void onGpioDataRecv();

public slots:
    void test(QString x);
    // Refresh ComPortList
    void refresh();
    //Returns List of COM ports to be added to drop down menu
    QStringList getComPortList();
    void setReadPin(int);
    QString getReadouts(int pin) const;

private slots:
    void handleReadyRead();
//    void handleTimeout();
//    void handleError(QSerialPort::SerialPortError error);

private:
//    static Serial* _instance;

//    Serial(const Serial&);
//    Serial& operator=(const Serial&);

    QStringList portList();
    void refreshPortList(bool arg);
    void onClick(bool arg);

    bool isConnected();
    void Connect(bool);

    QSerialPortInfo m_portInfo;
    QSerialPort *m_qSerialPort;
    static QList<QSerialPortInfo> m_serialPortList;
    static void m_findComPort();
    bool m_connected;
    int m_pinNo;
    QVector<QString> m_gpioData;

    QByteArray m_readData;
    QTimer m_timer;
    QStringList m_portNameList;


};

#endif // SERIAL_H
