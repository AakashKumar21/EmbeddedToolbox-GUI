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
    Q_PROPERTY(bool comPort WRITE setPort)

    Q_PROPERTY(bool connected READ isConnected WRITE Connect)
    Q_PROPERTY(int port WRITE setPort)
    Q_PROPERTY(NOTIFY onNotifyDatRecv)
    Q_PROPERTY(NOTIFY i2cDevicesRecv)


public:

    explicit Serial(QObject *parent = nullptr);
    ~Serial();
    bool Write(QByteArray);
    QSerialPort::SerialPortError getInfo() const; //  Will return SerialInfo including connected/disconnected
    void setPort(int port_index = 0 ); // index of QList<QSerialPortInfo>
    QSerialPort::SerialPortError Begin(enum QSerialPort::BaudRate);
    void End();

    QByteArray getData();

Q_INVOKABLE QVector<QString> getReadoutsAll();
Q_INVOKABLE QVector<int> getI2cAd();

signals:
    void NotifyData();
    void onClickRefresh();
    void onGpioDataRecv();
    void onNotifyDatRecv();
    void i2cDevicesRecv();

public slots:
    // Refresh ComPortList
    void refresh();

    //Returns List of COM ports to be added to drop down menu
    QStringList getComPortList() const;

    //GPIO Control methods
    bool set_pinMode(int pin, bool pinmode);
    bool set_digitalWrite(int pin,bool output) ;
    bool set_analogWrite(int pin, int duty) ;
    bool set_digitalRead(int pin) ;
    bool set_AnalogRead(int pin) ;

    //I2C Methods
    bool i2c_scan();
    bool send_Sync();

private slots:
    void handleReadyRead();

private:
    QStringList portList() const;
    void refreshPortList(bool arg) const;
    void onClick(bool arg) const;

    bool isConnected();
    void Connect(bool);

    QSerialPortInfo m_portInfo;
    QSerialPort *m_qSerialPort;
    static QList<QSerialPortInfo> m_serialPortList;
    static void m_findComPort();
    bool m_connected;
    int m_pinNo;
    QVector<QString> m_gpioData;
    QVector<int> m_i2c_ad;

    QByteArray m_readData;
    QTimer m_timer;
    QStringList m_portNameList;
};

#endif // SERIAL_H
