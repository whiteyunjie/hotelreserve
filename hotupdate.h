#ifndef HOTUPDATE_H
#define HOTUPDATE_H

#include <QDialog>
#include "hotels.h"
#include "hotelmanager.h"
#include "orders.h"
extern int hotelposition;
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<guestroom *>room_List;  //全局变量存放酒店客房的信息
extern QList<orders *> ord_List;//存放订单信息的容器
extern int cuschange[10];
namespace Ui {
class hotupdate;
}

class hotupdate : public QDialog
{
    Q_OBJECT

public:
    explicit hotupdate(QWidget *parent = 0);
    void updatehotinfo();
    ~hotupdate();

private slots:
    void on_hotchange_clicked();

    void on_changebck_clicked();
signals:
    void uphothot();

private:
    Ui::hotupdate *ui;
};

#endif // HOTUPDATE_H
