#ifndef CUSREG_H
#define CUSREG_H

#include <QDialog>
#include "hotelreserve.h"
#include "manipulate3.h"
#include "manipulate4.h"
extern int customerposition; //全局变量用来记录当前登录的客户在容器中索引

namespace Ui {
class cusreg;
}

class cusreg : public QDialog
{
    Q_OBJECT

public:
    explicit cusreg(QWidget *parent = 0);
    ~cusreg();

private:
    Ui::cusreg *ui;
private slots:
    void s_cusreg();
    void on_cusclose_clicked();
    void on_cusregisiter_clicked();
};

#endif // CUSREG_H
