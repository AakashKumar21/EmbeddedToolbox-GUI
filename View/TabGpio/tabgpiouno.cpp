#include "tabgpiouno.h"
#include "ui_tabgpiouno.h"
#include <QDebug>
#include "serialcommands.h"

TabGpioUno::TabGpioUno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabGpioUno),
    m_serialConn(Serial::getInstance())
{
    ui->setupUi(this);
    m_init_gui();
}

TabGpioUno::~TabGpioUno()
{
    delete ui;
}

void TabGpioUno::m_init_gui()
{

    QString tmp = "D";
    for(int i{}; i<m_no_of_pins_per_group; i++)
    {
        m_listLabel.append(new QLabel(tmp + QString::number(i),this));
        m_listCheckBox_PinMode.append(new QCheckBox("Input",this));
        m_listCheckBox_Output.append(new QCheckBox("Float",this));
        m_listReadout.append(new QLabel("Low",this));
        m_listReadout[i]->setDisabled(true);
        m_listReadout[i]->setStyleSheet(("QLabel { background-color : #42A5F5 ; color : white; }"));
        m_listReadout[i]->setAlignment(Qt::AlignCenter);

        m_listCheckBox_PinMode[i]->setObjectName(QString::number(i));
        m_listCheckBox_Output[i]->setObjectName(QString::number(i));
        m_listReadout[i]->setObjectName(QString::number(i));

        ui->gridLayout_3->addWidget(m_listLabel[i],0,i);
        ui->gridLayout_3->addWidget(m_listCheckBox_PinMode[i],1,i);
        ui->gridLayout_3->addWidget(m_listCheckBox_Output[i],2,i);
        ui->gridLayout_3->addWidget(m_listReadout[i],3,i);

        connect(m_listCheckBox_PinMode[i], &QCheckBox::stateChanged,
                this, &TabGpioUno::on_PinmodeClicked);
        connect(m_listCheckBox_Output[i], &QCheckBox::stateChanged,
                this, &TabGpioUno::on_OutputClicked);
    }
}

void TabGpioUno::on_PinmodeClicked()
{
    QObject *senderObj = sender(); // to get Sender object
    QString senderObjName = senderObj->objectName();
    char pin_no = senderObjName.toInt();
    auto checkBox = dynamic_cast<QCheckBox*>(senderObj);

    if(checkBox)
    {
        // PinMode OUTPUT
        qDebug() << "PinMode: " << QString::number(pin_no) << "Set to";
        if(checkBox->isChecked())
        {
            qDebug() << "Output";
            if( m_serialConn->Write(Inst::PinMode::PinMode_Out,pin_no) )
            {
                qDebug() << "Error Writing";
            }
            else{                                           //IF SUCCESS
                m_listCheckBox_PinMode[pin_no]->setText("Output");
                m_listCheckBox_Output[pin_no]->setText(
                            m_listCheckBox_Output[pin_no]->isChecked()?"High":"Low");
            }
        }
        else {
            qDebug() << "Input";
            if (m_serialConn->Write(Inst::PinMode::PinMode_In, pin_no))
            {
                qDebug() << "Error Writing";
            }
            else{   //IF SUCCESS
                m_listCheckBox_PinMode[pin_no]->setText("Input");
                m_listCheckBox_Output[pin_no]->setText(
                            m_listCheckBox_Output[pin_no]->isChecked()?"PullUp":"Float");
                m_listReadout[pin_no]->setEnabled(true);
            }
        }
    }
}

void TabGpioUno::on_OutputClicked()
{
    QObject *senderObj = sender(); // to get Sender object
    QString senderObjName = senderObj->objectName();
    char pin_no = senderObjName.toInt();

    auto checkBox = dynamic_cast<QCheckBox*>(senderObj);
    if(checkBox)
    {
        qDebug() << "Output: " << QString::number(pin_no) << " Set to";
        if(checkBox->isChecked())
        {
            qDebug() << "High";
            m_serialConn->Write(Inst::PinMode::PinHigh,
                                pin_no);
            m_listCheckBox_Output[pin_no]->setText(
                        m_listCheckBox_PinMode[pin_no]->isChecked()?"High":"PullUp");
        }
        else {
            qDebug() << "Low";
            m_serialConn->Write(Inst::PinMode::PinLow,
                                pin_no);
            m_listCheckBox_Output[pin_no]->setText(
                        m_listCheckBox_PinMode[pin_no]->isChecked()?"Low":"Float");
        }
    }
}
