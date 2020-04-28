#ifndef TAB_GPIO_H
#define TAB_GPIO_H

#include <QWidget>
#include <QCheckBox>
#include "serial.h"


namespace Ui {
class tab_gpio;
}

class TabGpio : public QWidget
{
    Q_OBJECT

public:
    explicit TabGpio(QWidget *parent = nullptr);
    ~TabGpio();

private slots:
    void on_pinMode_0_stateChanged(int arg1);

    void on_output_0_stateChanged(int arg1);

private:
    Ui::tab_gpio *ui;
    Serial &m_serialConn;
    void _managePinModeText(QCheckBox&, bool); //  Manage PinMode CheckBox text
    void _manageOutputText(QCheckBox&, bool); //  Manage Output CheckBox text
};

#endif // TAB_GPIO_H
