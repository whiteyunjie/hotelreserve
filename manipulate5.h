#ifndef MANIPULATE5_H
#define MANIPULATE5_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QList>
#include "hotelgovern.h"

extern QList<hotelgovern *> hotgov_List;  //存放所有酒店管理员
bool Connect_hotgov();
//创建表格
bool createTable_hotgov();

bool judgetable_hotgov(); //判断表格是否存在
bool insertSQL_hotgov(QString servience, QString passward,QString name);
//清空表格信息
void clearSQL_hotgov();
bool update_hotgov();
void showtable_hotgov();
void clearall_hotgov();  //删除表格
//登录
bool login_hotgov(QString servience,QString passward);
//注册
bool register_hotgov(QString servience,QString passward,QString name);
//断开连接
void close_hotgov();
//将表格中信息读入容器中
//同步初始化酒店的四类客房和酒店管理员对象
void read_hotgov();

#endif // MANIPULATE5_H
