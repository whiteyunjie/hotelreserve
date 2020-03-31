#ifndef CUSCHANGEINFO_H
#define CUSCHANGEINFO_H

#include <QDialog>
#include "customers.h"

extern int cuschange[10];
extern QList<customers *> cus_List;//存放客户信息数据的容器
extern int customerposition; //全局变量用来记录当前登录的客户的索引

namespace Ui {
class cuschangeinfo;
}

class cuschangeinfo : public QDialog
{
    Q_OBJECT

public:
    explicit cuschangeinfo(QWidget *parent = 0);
    ~cuschangeinfo();

private slots:
    void on_change_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cuschangeinfo *ui;
};

#endif // CUSCHANGEINFO_H
