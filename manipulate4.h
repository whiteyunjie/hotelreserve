#ifndef MANIPULATE4_H
#define MANIPULATE4_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QList>
#include "guestroom.h"

extern QList<guestroom *>room_List;  //全局变量存放酒店客房的信息
extern int roomchange[10];

//客户数据库相关操作以及将数据库的信息存入容器中
//连接或创建数据库
bool Connect_room();
//创建表格
bool createTable_room();

bool judgetable_room();//判断表格是否存在
bool insertSQL_room(QString type, QString belongname,QString roomphotoadd,int roomnum,int vacanynum,int price,float discount);

//清空表格信息
void clearSQL_room();
//删除某一条
void clearall_room(); //删除表格
//输出表格中信息
void showtable_room();
//断开连接
void close_room();
//将表格中信息读入容器中
//通过数据库初始化客房信息
void read_room();
//更新数据库
bool update_room();
 //程序运行结束时释放掉内存
 void delete_room();
#endif // MANIPULATE4_H
