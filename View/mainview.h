#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "ui_mainview.h"
#include "View/tab_setup.h"
#include "View/TabGpio/tabgpiouno.h"
#include "View/TabAdc/tabadcuno.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent,TabSetup &gpio,TabGpioUno &gpio_uno, TabAdcUno &adc_uno);
//    MainView() = default;
    ~MainView();

private slots:


private:
    Ui::MainView *ui;
    TabSetup &m_tabSetup;
    TabGpioUno &m_tabGpioUno;
    TabAdcUno &m_tabAdcUno;
};
#endif // MAINVIEW_H
