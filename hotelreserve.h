#ifndef HOTELRESERVE_H
#define HOTELRESERVE_H

#include <QDialog>
#include "orders.h"
#include "guestroom.h"
#include "hotels.h"
#include "hotelmanager.h"
#include "orderscus.h"
#include "cuschangeinfo.h"
#include "manipulatesql.h"
#include "manipulate2.h"
#include "hoteldetails.h"
#include "manipulate3.h"
extern QList<customers *> cus_List;//存放客户信息数据的容器
extern QList<orders *> ord_List;//存放订单信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<guestroom *>room_List;  //全局变量存放酒店客房的信息
extern int cuschange[10];
extern int hotchange[10];  //用来记录发生改变的信息在list中的索引，以便最后对数据库进行更改(一般不会超过十个)
extern int ordchange[20];//记录发生改变的订单在list中的索引以便最后写入数据库
extern int roomchange[10]; //记录发生改变的客房在list中的索引以便写入数据库
extern int hotelposition;  //全局变量用来记录当前所登录的酒店的索引
extern int customerposition; //全局变量用来记录当前登录的客户的索引
namespace Ui {
class hotelreserve;
}

class hotelreserve : public QDialog
{
    Q_OBJECT

public:
    explicit hotelreserve(QWidget *parent = 0);
    ~hotelreserve();

private slots:
    void on_enquery_clicked();

    void on_fordetails_clicked();

    void on_lookorders_clicked();

    void on_changeinfo_clicked();

    void on_pushButton_clicked();

    void uphot();

private:
    Ui::hotelreserve *ui;
};

#endif // HOTELRESERVE_H
