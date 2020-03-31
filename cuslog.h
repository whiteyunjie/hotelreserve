#ifndef CUSLOG_H
#define CUSLOG_H

#include <QDialog>
#include "hotelreserve.h"
#include "manipulate3.h"
#include "manipulate4.h"
extern int customerposition; //全局变量用来记录当前登录的客户在容器中索引
namespace Ui {
class cuslog;
}

class cuslog : public QDialog
{
    Q_OBJECT

public:
    explicit cuslog(QWidget *parent = 0);
    ~cuslog();

private:
    Ui::cuslog *ui;
private slots:
    void s_cuslog();
    void on_pushButton_clicked();
};

#endif // CUSLOG_H
