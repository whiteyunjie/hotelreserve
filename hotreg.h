#ifndef HOTREG_H
#define HOTREG_H

#include <QDialog>
#include "manipulate2.h"
extern int hotelposition;  //全局变量用来记录当前所登录的酒店在容器中的索引

namespace Ui {
class hotreg;
}

class hotreg : public QDialog
{
    Q_OBJECT

public:
    explicit hotreg(QWidget *parent = 0);
    ~hotreg();

private:
    Ui::hotreg *ui;
private slots:
    void s_hotreg();
    void on_hotregister_clicked();
    void on_hotregback_clicked();
};

#endif // HOTREG_H
