#ifndef TAB_SETUP_H
#define TAB_SETUP_H

#include <QWidget>

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

private:
    Ui::tab_setup *ui;
};

#endif // TAB_SETUP_H
