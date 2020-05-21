#ifndef TAB_SETUP_H
#define TAB_SETUP_H

#include <QObject>
#include "serial.h"
#include <QDir>

namespace Ui {
class tab_setup;
}

class TabSetup : public QObject
{
    Q_OBJECT

public:
    explicit TabSetup(QObject *parent = nullptr);
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
//    Serial &m_serialConn;
};

#endif // TAB_SETUP_H
