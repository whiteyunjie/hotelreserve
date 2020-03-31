#include "platformlog.h"

bool Connect_plat()     //连接数据库
{
    QSqlDatabase database;
    if(QSqlDatabase::contains("sqlite1")) database=QSqlDatabase::database("sqlite1");
    else
    {
        database=QSqlDatabase::addDatabase("QSQLITE","sqlite1");
        database.setDatabaseName("platform.db");
        QSqlQuery query(database);
    }
    QSqlQuery query(database);
    if(!database.open())
    {
        qDebug()<<"连接数据库失败"<<query.lastError();
        return false;
    }
    else return true;
}

//创建表格并加入平台的id和密码
bool createTable_plat()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    bool jud=query.exec("create table platform(id varchar(20),platpassward varchar(20))");
    if(!jud)
    {
        qDebug()<<"创建失败"<<query.lastError();
        return false;
    }
    QString str="insert into platform values (?,?)";
    query.prepare(str);
    query.addBindValue("2017011626");
    query.addBindValue("8826337");
    if(query.exec())
    {
        qDebug()<<"创建成功";
        return true;
    }
    qDebug()<<"创建失败"<<query.lastError();
    return false;
}
bool judgetable_plat() //判断表格是否存在
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    return database.tables().contains("platform");
}

bool selectSQL_plat(QString id,QString platpassward)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str=QString("select * from platform where id='%1' and platpassward='%2'").arg(id).arg(platpassward);
    query.exec(str);
    query.last();
    int record=query.at()+1;
    if(record==0) return false;
    return true;
}






