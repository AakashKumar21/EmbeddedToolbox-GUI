#include "tabadcuno.h"
#include "ui_tabadcuno.h"
#include <QtMath>

TabAdcUno::TabAdcUno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabAdcUno)
{
    ui->setupUi(this);
    m_init_gui();
}

TabAdcUno::~TabAdcUno()
{
    delete ui;
}

void TabAdcUno::on_AdcClicked()
{

}

void TabAdcUno::m_init_gui()
{
    QString tmp = "ADC";
    for(int i{}; i<no_of_adc; i++)
    {
        m_listCheckBox_adc.append(new QCheckBox(tmp + QString::number(i),this));
        m_listLcdReadout.append(new QLCDNumber(this));

        ui->lo_AdcSelect->addWidget(m_listCheckBox_adc[i],i,0);
        ui->lo_AdcSelect->addWidget(m_listLcdReadout[i],i,1);
        m_listLcdReadout[i]->display(i*i);
//        m_listLcdReadout[i]->
        connect(m_listCheckBox_adc[i], &QCheckBox::stateChanged,
                this, &TabAdcUno::on_AdcClicked);
    }

    for(int i{}; i<=7; i++)
    {
        ui->dropdown_prescale->addItem(QString::number(qPow(2,i)));
    }
}
