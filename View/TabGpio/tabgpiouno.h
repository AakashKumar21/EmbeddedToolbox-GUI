#ifndef TABGPIOUNO_H
#define TABGPIOUNO_H

#include "serial.h"
#include <QObject>


class TabGpioUno : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool pinModes READ isChecked WRITE setChecked NOTIFY checkChanged)
//    Q_PROPERTY(QString pin_no WRITE setId)

public:
    explicit TabGpioUno(QObject *parent = nullptr);
    ~TabGpioUno();

signals:
    void checkChanged();

private:
    int m_no_of_pins_per_group = 14;
    Serial* m_serialConn;

    void setChecked(int value);
    void setId(QString);
    bool isChecked();

    void m_init_gui();
//    QList <QCheckBox*> m_listCheckBox_PinMode;
//    QList <QCheckBox*> m_listCheckBox_Output;
//    QList <QLabel*> m_listLabel;
//    QList <QLabel*> m_listReadout;
    void on_PinmodeClicked();
    void on_OutputClicked();
    void set_Readout(int,bool);

private slots:
    void handleData();
    void on_btnSync_clicked();
};

#endif // TABGPIOUNO_H
