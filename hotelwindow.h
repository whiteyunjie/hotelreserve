#ifndef HOTELWINDOW_H
#define HOTELWINDOW_H

#include "hotels.h"
#include "hotelmanager.h"
#include "hotupdate.h"
#include "roominformation.h"
#include "orders.h"
#include "manipulate2.h"
#include "manipulate5.h"
#include "managers.h"
#include <QDialog>
#include <QDebug>
#include <Qvector>
#include <QDate>
#include <QIcon>
#include <QLabel>
extern int hotelposition;  //全局变量用来记录当前所登录的酒店在容器中的索引
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<guestroom *> room_List; //存放客房数据
extern QList<orders *> ord_List; //订单数据
extern QList<hotelgovern *> hotgov_List;  //存放所有酒店管理员
extern bool isman;
namespace Ui {
class hotelwindow;
}

class hotelwindow : public QDialog
{
    Q_OBJECT

public:
    explicit hotelwindow(QWidget *parent = 0);
    ~hotelwindow();
private slots:
    void on_updateinfomation_clicked();

    void on_addroom_clicked();

    void on_changeroom_clicked();

    void on_deleteroom_clicked();

    void on_acceptorder_clicked();

    void on_agreerefund_clicked();

    void on_savedata_clicked();

    void updatehotorders();

    void updatetable();

    void on_addman_clicked();
private:
    Ui::hotelwindow *ui;
};

#endif // HOTELWINDOW_H
