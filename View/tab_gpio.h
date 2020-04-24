#ifndef TAB_GPIO_H
#define TAB_GPIO_H

#include <QWidget>

namespace Ui {
class tab_gpio;
}

class TabGpio : public QWidget
{
    Q_OBJECT

public:
    explicit TabGpio(QWidget *parent = nullptr);
    ~TabGpio();

private:
    Ui::tab_gpio *ui;
};

#endif // TAB_GPIO_H
