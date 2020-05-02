#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "ui_mainview.h"
#include "View/tab_setup.h"
#include "View/TabGpio/tabgpiouno.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent,TabSetup &gpio,TabGpioUno &gpio_uno);
//    MainView() = default;
    ~MainView();

private:
    Ui::MainView *ui;
    TabSetup &m_tabSetup;
    TabGpioUno &m_tabGpioUno;
};
#endif // MAINVIEW_H
