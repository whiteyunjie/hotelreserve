#ifndef PLATFORM_H
#define PLATFORM_H

#include <QDialog>
#include "platformlog.h"
#include "manipulate3.h"
#include "manipulatesql.h"

namespace Ui {
class platform;
}

class platform : public QDialog
{
    Q_OBJECT

public:
    explicit platform(QWidget *parent = 0);
    ~platform();

private:
    Ui::platform *ui;
private slots:
    void s_platlog();
    void on_reg_plat_clicked();
    void on_back_plat_clicked();
};

#endif // PLATFORM_H
