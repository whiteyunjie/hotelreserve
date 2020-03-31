#ifndef PLATWINDOW_H
#define PLATWINDOW_H

#include <QDialog>
#include <QDebug>
#include "hotels.h"
#include "hotelmanager.h"
#include "customers.h"
#include "manipulate3.h"

extern int hotelposition;
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<customers *> cus_List;//存放客户信息数据的容器
extern int hotchange[10];
namespace Ui {
class platwindow;
}

class platwindow : public QDialog
{
    Q_OBJECT

public:
    explicit platwindow(QWidget *parent = 0);
    ~platwindow();
    void showagain(); //刷新酒店表格

private slots:
    void on_changeau_clicked();

    void on_save_clicked();

private:
    Ui::platwindow *ui;
};

#endif // PLATWINDOW_H
