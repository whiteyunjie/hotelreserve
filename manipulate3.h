#ifndef MANIPULATE3_H
#define MANIPULATE3_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QList>
#include "hotels.h"
#include "hotelmanager.h"

extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern int hotchange[10]; //用来记录发生改变的信息在list中的索引，以便最后对数据库进行更改(一般不会超过十个)

//客户数据库相关操作以及将数据库的信息存入容器中
//连接或创建数据库
bool Connect_hot();
//创建表格
bool createTable_hot();

bool judgetable_hot();//判断表格是否存在
bool insertSQL_hot(QString servicelience, QString address, QString city, QString hotelname, QString telephone, QString hotpassward, QString photoadd, bool authority,
                   float jud, int peopleass,int minprice); //与注册界面顺序一样，插入数据，即注册用户

//判断是否存在该用户
bool selectSQL_hot(QString servicelience,QString hotpassward);
//清空表格信息
void clearSQL_hot();
//删除某一条
void clear_hot(QString servicelience);
void clearall_hot(); //删除表格
//输出表格中信息
void showtable_hot();                //微调
//断开连接
void close_hot();
//将表格中信息读入容器中
//同步初始化酒店的四类客房和酒店管理员对象
void read_hot();
//注册
int register_hot(QString hotelname, QString servicelience, QString address, QString city, QString telephone, QString hotpassward);
//登录
int login_hot(QString servicelience,QString hotpassward);

//更新数据库
bool update_hot();
 //程序运行结束时释放掉内存
 void delete_hot();

#endif // MANIPULATE3_H
