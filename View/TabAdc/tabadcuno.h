#ifndef TABADCUNO_H
#define TABADCUNO_H

//#include <QWidget>
//#include <QLabel>
//#include <QCheckBox>
//#include <QLCDNumber>
#include <QObject>

namespace Ui {
class TabAdcUno;
}

class TabAdcUno : public QObject
{
    Q_OBJECT

public:
    explicit TabAdcUno(QObject *parent = nullptr);
    ~TabAdcUno();

private:
    Ui::TabAdcUno *ui;
    int no_of_adc = 6;
//    QList <QCheckBox*> m_listCheckBox_adc;
//    QList <QLCDNumber*> m_listLcdReadout;
    void on_AdcClicked();
    void m_init_gui();
};

#endif // TABADCUNO_H
