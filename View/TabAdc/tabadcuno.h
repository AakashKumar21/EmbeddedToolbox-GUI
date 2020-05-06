#ifndef TABADCUNO_H
#define TABADCUNO_H

#include <QWidget>

namespace Ui {
class TabAdcUno;
}

class TabAdcUno : public QWidget
{
    Q_OBJECT

public:
    explicit TabAdcUno(QWidget *parent = nullptr);
    ~TabAdcUno();

private:
    Ui::TabAdcUno *ui;
};

#endif // TABADCUNO_H
