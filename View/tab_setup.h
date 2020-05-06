#ifndef TAB_SETUP_H
#define TAB_SETUP_H

#include <QWidget>
#include "serial.h"
#include <QDir>

namespace Ui {
class tab_setup;
}

class TabSetup : public QWidget
{
    Q_OBJECT

public:
    explicit TabSetup(QWidget *parent = nullptr);
    ~TabSetup();

private slots:

    void on_dropdown_comPortSelect_activated(int index);

    void on_btn_refresh_port_clicked();

    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

    void on_dropdown_themes_activated(int index);

private:
    Ui::tab_setup *ui;
    QStringList m_styleSheets;
    Serial &m_serialConn;
};

#endif // TAB_SETUP_H
