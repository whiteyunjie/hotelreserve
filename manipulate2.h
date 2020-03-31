#ifndef MANIPULATE2_H
#define MANIPULATE2_H

//实现订单信息数据库的操作以及将酒店信息从数据库传入容器的一系列函数

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QList>
#include <QDate>
#include "orders.h"

extern QList<orders *> ord_List;  //全局变量作为存放订单信息的容器
extern int ordchange[20]; //记录发生改变的订单在list中的索引以便最后写入数据库

//订单数据库相关操作以及将数据库的信息存入容器中
//连接或创建数据库
bool Connect_ord();

//创建表格
bool createTable_ord();

bool judgetable_ord(); //判断表格是否存在
bool insertSQL_ord(QString cusname,QString cusiphone,QString hotelname,QString hoteladdress,QString situation,QString cusrequest,QString type,
                   QDate reservedate,int reservedays,int price,int ordnum) ;//插入数据到数据库



//清空表格信息
void clearSQL_ord();
//删除某一条
void clear_ord(int ordnum);
//输出表格中信息
void showtable_ord();

//断开连接
void close_ord();
//将表格中信息读入容器中
void read_ord();

//更新数据库
bool update_ord();

//程序运行结束时释放掉内存
void delete_ord();
#endif // MANIPULATE2_H
