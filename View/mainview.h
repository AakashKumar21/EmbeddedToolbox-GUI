#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "ui_mainview.h"
#include "ui_tab_gpio.h"
#include "View/tab_gpio.h"
#include "View/tab_setup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent,TabSetup &gpio, TabGpio &setup);
//    MainView() = default;
    ~MainView();

private:
    Ui::MainView *ui;
    TabSetup &m_tabSetup;
    TabGpio &m_tabGpio;
};
#endif // MAINVIEW_H
