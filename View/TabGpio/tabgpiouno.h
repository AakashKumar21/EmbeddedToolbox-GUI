#ifndef TABGPIOUNO_H
#define TABGPIOUNO_H

#include <QWidget>

namespace Ui {
class TabGpioUno;
}

class TabGpioUno : public QWidget
{
    Q_OBJECT

public:
    explicit TabGpioUno(QWidget *parent = nullptr);
    ~TabGpioUno();

private:
    Ui::TabGpioUno *ui;
};

#endif // TABGPIOUNO_H
