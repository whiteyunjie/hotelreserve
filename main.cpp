#include "mainwindow.h"
#include "login.h"
#include "cuslog.h"
#include "cusreg.h"
#include "hotlog.h"
#include "hotreg.h"
#include "platform.h"
#include "customers.h"
#include "orders.h"
#include "hotels.h"
#include "hotelmanager.h"
#include "hotelgovern.h"
#include <QList>
#include <QApplication>


QList<customers *> cus_List;//存放客户信息数据的容器
QList<orders *> ord_List;//存放订单信息的容器
QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
QList<guestroom *> room_List; //存放客房信息
QList<hotelgovern *> hotgov_List;  //存放所有酒店管理员
bool isman=false; //判断是酒店还是管理员登录了账号
int cuschange[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int hotchange[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};  //用来记录发生改变的信息在list中的索引，以便最后对数据库进行更改(一般不会超过十个)
int ordchange[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//记录发生改变的订单在list中的索引以便最后写入数据库
int hotelposition;  //全局变量用来记录当前所登录的酒店的索引
int customerposition; //全局变量用来记录当前登录的客户的索引
int roomposition;//记录当前所更改的客房的索引 ？是否需要

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login s;
    cuslog c1;
    cusreg c2;
    hotlog h1;
    hotreg h2;
    platform p;
    QFile styleFile(":/beautify2.qss");
    styleFile.open(QIODevice::ReadOnly);
    QString setStyleSheet(styleFile.readAll());
    a.setStyleSheet(setStyleSheet);
    QObject::connect(&s,SIGNAL(e_cuslog()),&c1,SLOT(s_cuslog()));
    QObject::connect(&s,SIGNAL(e_cusreg()),&c2,SLOT(s_cusreg()));
    QObject::connect(&s,SIGNAL(e_hotlog()),&h1,SLOT(s_hotlog()));
    QObject::connect(&s,SIGNAL(e_hotreg()),&h2,SLOT(s_hotreg()));
    QObject::connect(&s,SIGNAL(e_platlog()),&p,SLOT(s_platlog()));

    s.exec();
    return a.exec();
}
