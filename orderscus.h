#ifndef ORDERSCUS_H
#define ORDERSCUS_H

#include <QDialog>
#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include "hotupdate.h"
#include "guestroom.h"
#include "orders.h"
#include "customers.h"
#include "trade.h"
#include "assess.h"
extern int hotelposition;  //全局变量用来记录当前所登录的酒店在容器中的索引
extern int cuschange[10];
extern int customerposition; //全局变量用来记录当前登录的客户的索引
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<guestroom *> room_List; //存放客房数据
extern QList<orders *> ord_List;
extern QList<customers *> cus_List;//存放客户信息数据的容器

namespace Ui {
class orderscus;
}

class orderscus : public QDialog
{
    Q_OBJECT

public:
    explicit orderscus(QWidget *parent = 0);
    ~orderscus();
    void updatetable_ord();

private slots:
    void on_checkin_clicked();

    void on_refund_clicked();

    void on_checkout_clicked();

    void on_back_clicked();

    void updatehotelss();
 signals:
    void uphotel();

private:
    Ui::orderscus *ui;
};

#endif // ORDERSCUS_H
