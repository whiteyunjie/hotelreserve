#ifndef HOTELDETAILS_H
#define HOTELDETAILS_H

#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include "hotupdate.h"
#include "guestroom.h"
#include "orders.h"
#include "customers.h"
#include "trade.h"
extern int hotelposition;  //全局变量用来记录当前所登录的酒店在容器中的索引
extern int cuschange[10];
extern int ordchange[20];
extern int customerposition; //全局变量用来记录当前登录的客户的索引
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<guestroom *> room_List; //存放客房数据
extern QList<orders *> ord_List;
extern QList<customers *> cus_List;//存放客户信息数据的容器

namespace Ui {
class hoteldetails;
}

class hoteldetails : public QDialog
{
    Q_OBJECT

public:
    explicit hoteldetails(QWidget *parent = 0);
    ~hoteldetails();

private slots:
    void on_order_clicked();

    void on_hotdetailback_clicked();

private:
    Ui::hoteldetails *ui;
};

#endif // HOTELDETAILS_H
