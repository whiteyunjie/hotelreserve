#ifndef MANIPULATESQL_H
#define MANIPULATESQL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QList>
#include "customers.h"

extern QList<customers *> cus_List;  //全局变量作为存放客户信息的容器
extern int cuschange[10];

//客户数据库相关操作以及将数据库的信息存入容器中
//连接或创建数据库
bool Connect_cus();

//创建表格
bool createTable_cus();

bool judgetable_cus(); //判断表格是否存在

int insertSQL_cus(QString iphonenum,QString identityid, QString name, QString sex, QString passward); //与注册界面顺序一样，插入数据，即注册用户

//判断是否存在该用户
bool selectSQL_cus(QString iphonenum,QString passward);

bool update_cus(QString passward,QString iphonenum);
//清空表格信息
void clearSQL_cus();
void clear_onecus(QString name);
//输出表格中信息
void showtable_cus();
//断开连接
void close_cus();
//将表格中信息读入容器中
void read_cus();
//注册
int register_cus(QString iphonenum,QString identityid, QString name, QString sex, QString passward);
//登录
int login_cus(QString iphonenum,QString passward);
//更新数据库
bool updatesql_cus();
//程序运行结束时释放掉内存
void delete_cus();

#endif // MANIPULATESQL_H
