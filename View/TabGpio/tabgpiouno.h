#ifndef TABGPIOUNO_H
#define TABGPIOUNO_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include "serial.h"

namespace Ui {
class TabGpioUno;
}

class TabGpioUno : public QWidget
{
    Q_OBJECT

public:
    explicit TabGpioUno(QWidget *parent = nullptr);
    ~TabGpioUno();


private:
    Ui::TabGpioUno *ui;
    int m_no_of_pins_per_group = 14;
    Serial* m_serialConn;

    void m_init_gui();
    QList <QCheckBox*> m_listCheckBox_PinMode;
    QList <QCheckBox*> m_listCheckBox_Output;
    QList <QLabel*> m_listLabel;
    QList <QLabel*> m_listReadout;
    void on_PinmodeClicked();
    void on_OutputClicked();

private slots:
    void handleData();
    void on_btnSync_clicked();
};

#endif // TABGPIOUNO_H
