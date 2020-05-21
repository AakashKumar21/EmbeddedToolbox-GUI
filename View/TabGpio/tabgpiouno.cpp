#include "tabgpiouno.h"
//#include "ui_tabgpiouno.h"
#include <QDebug>
#include "serialcommands.h"
#include <utility>

TabGpioUno::TabGpioUno(QObject *parent) :
    QObject(parent)
{
//    ui->setupUi(this);
    m_init_gui();
}

TabGpioUno::~TabGpioUno()
{
    //    delete ui;
}

void TabGpioUno::setChecked(int value)
{
    qDebug() << value;
}

void TabGpioUno::setId(QString arg)
{
    qDebug() << "Id: " << arg;
}

bool TabGpioUno::isChecked()
{
    qDebug () << "not connected";
    return true;
}

void TabGpioUno::m_init_gui()
{

    QString tmp = "D";
    for(int i{}; i<m_no_of_pins_per_group; i++)
    {
//        m_listLabel.append(new QLabel(tmp + QString::number(i),this));
//        m_listCheckBox_PinMode.append(new QCheckBox("Input",this));
//        m_listCheckBox_Output.append(new QCheckBox("Float",this));
//        m_listReadout.append(new QLabel("Low",this));
//        m_listReadout[i]->setAlignment(Qt::AlignCenter);

//        m_listCheckBox_PinMode[i]->setObjectName(QString::number(i));
//        m_listCheckBox_Output[i]->setObjectName(QString::number(i));
//        m_listReadout[i]->setObjectName(QString::number(i));

//        ui->gridLayout_3->addWidget(m_listLabel[i],0,i);
//        ui->gridLayout_3->addWidget(m_listCheckBox_PinMode[i],1,i);
//        ui->gridLayout_3->addWidget(m_listCheckBox_Output[i],2,i);
//        ui->gridLayout_3->addWidget(m_listReadout[i],3,i);

//        connect(m_listCheckBox_PinMode[i], &QCheckBox::stateChanged,
//                this, &TabGpioUno::on_PinmodeClicked);
//        connect(m_listCheckBox_Output[i], &QCheckBox::stateChanged,
//                this, &TabGpioUno::on_OutputClicked);
    }

    connect(m_serialConn, &Serial::NotifyData , this , &TabGpioUno::handleData );
}

void TabGpioUno::on_PinmodeClicked()
{
//    QObject *senderObj = sender(); // to get Sender object
//    QString senderObjName = senderObj->objectName();
//    char pin_no = senderObjName.toInt();
//    auto checkBox = dynamic_cast<QCheckBox*>(senderObj);

//    if(checkBox)
//    {
//        // PinMode OUTPUT
//        qDebug() << "PinMode: " << QString::number(pin_no) << "Set to";
//        if(checkBox->isChecked())
//        {
//            qDebug() << "Output";
//            if( m_serialConn->set_pinMode(PinMode::PinMode_Out,
//                                          static_cast<Pin>(pin_no)) )
//            {
//                qDebug() << "Error Writing";
//            }
//            else{                                           //IF SUCCESS
//                m_listCheckBox_PinMode[pin_no]->setText("Output");
//                m_listCheckBox_Output[pin_no]->setText(
//                            m_listCheckBox_Output[pin_no]->isChecked()?"High":"Low");
//                m_listReadout[pin_no]->setDisabled(true);
//                m_listReadout[pin_no]->setStyleSheet("");
//            }
//        }
//        else {
//            qDebug() << "Input";
//            if (m_serialConn->set_pinMode(PinMode::PinMode_In,
//                                          static_cast<Pin>(pin_no)) )
//            {
//                qDebug() << "Error Writing";
//            }
//            else{   //IF SUCCESS
//                m_listCheckBox_PinMode[pin_no]->setText("Input");
//                m_listCheckBox_Output[pin_no]->setText(
//                            m_listCheckBox_Output[pin_no]->isChecked()?"PullUp":"Float");
//                m_listReadout[pin_no]->setEnabled(true);
//            }
//        }
//    }
}

void TabGpioUno::on_OutputClicked()
{
//    QObject *senderObj = sender(); // to get Sender object
//    QString senderObjName = senderObj->objectName();
//    char pin_no = senderObjName.toInt();

//    auto checkBox = dynamic_cast<QCheckBox*>(senderObj);
//    if(checkBox)
//    {
//        qDebug() << "Output: " << QString::number(pin_no) << " Set to";
//        if(checkBox->isChecked())
//        {
//            qDebug() << "High";
//            m_serialConn->set_digitalWrite(static_cast<Pin>(pin_no),
//                                           Output::High);
//            m_listCheckBox_Output[pin_no]->setText(
//                        m_listCheckBox_PinMode[pin_no]->isChecked()?"High":"PullUp");
//        }
//        else {
//            qDebug() << "Low";
//            m_serialConn->set_digitalWrite(static_cast<Pin>(pin_no),
//                                           Output::Low);
//            m_listCheckBox_Output[pin_no]->setText(
//                        m_listCheckBox_PinMode[pin_no]->isChecked()?"Low":"Float");
//        }
//    }
}

void TabGpioUno::set_Readout(int pin,bool state)
{
//    if(state)
//    {
//        if(m_listReadout[pin]->isEnabled())
//        {
//            m_listReadout[pin]->setText("High");
//            m_listReadout[pin]->setStyleSheet
//                    ("QLabel { color : Red; }");
//        }
//    }
//    else
//    {
//        if(m_listReadout[pin]->isEnabled())
//        {
//            m_listReadout[pin]->setText("Low");
//            m_listReadout[pin]->setStyleSheet
//                    ("QLabel { color : Sky Blue; }");
//        }
//    }
}

void TabGpioUno::handleData()
{
    auto data = m_serialConn->getData();

    for(int i=0; i<8; i++)
    {
        // PORTB
        if(data[1] & (1<<i))
        {
            if(i+8 < 14){
                set_Readout(i+8,true);
            }
        }
        else
        {
            if(i+8 < 14){
                set_Readout(i+8,false);
            }
        }

        // PORTD
        if(data[2] & (1<<i))
        {
          set_Readout(i,true); // BUG PRONE
        }
        else
        {
            set_Readout(i,false);
        }
    }
}

void TabGpioUno::on_btnSync_clicked()
{
    qDebug() << "Sending Sync";
    m_serialConn->send_Sync();
}
