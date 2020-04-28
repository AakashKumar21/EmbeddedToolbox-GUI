#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>

// This in singleton class
class Serial : public QObject
{
    Q_OBJECT
public:

    static Serial* getInstance();

    QSerialPort::SerialPortError sendReset();
    void Write(char cmd);
    void Write(char cmd, char ins);
    void Write(char cmd, char ins, char);
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
