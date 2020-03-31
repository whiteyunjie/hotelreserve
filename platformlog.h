#ifndef PLATFORMLOG_H
#define PLATFORMLOG_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QObject>
//用来连接一个记录平台账号和密码的数据库以实现登录操作
bool Connect_plat();
bool createTable_plat();
bool judgetable_plat();
bool selectSQL_plat(QString id,QString platpassward);

#endif // PLATFORMLOG_H
