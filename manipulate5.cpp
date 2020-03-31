#include "manipulate5.h"
bool Connect_hotgov()
{
    QSqlDatabase database;
    if(QSqlDatabase::contains("sqlite1")) database=QSqlDatabase::database("sqlite1");
    else
    {
        database=QSqlDatabase::addDatabase("QSQLITE","sqlite1");
        database.setDatabaseName("hotelreservation.db");
    }
    QSqlQuery query(database);
    if(!database.open())
    {
        qDebug()<<"连接数据库失败"<<query.lastError();
        return false;
    }
    else return true;
}

//创建表格
bool createTable_hotgov()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    bool jud=query.exec("create table hotelgoverns(servience varchar(20),passward varchar(20),name varchar(20))");
    if(!jud)
    {
        qDebug()<<"创建失败"<<query.lastError();
        return false;
    }
    else return true;
}

bool judgetable_hotgov() //判断表格是否存在
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    return database.tables().contains("hotelgoverns");
}
bool insertSQL_hotgov(QString servience, QString passward,QString name)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="insert into hotelgoverns values (?,?,?)";
    query.prepare(str);
    query.addBindValue(servience);
    query.addBindValue(passward);
    query.addBindValue(name);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
        return false;
    }
    else{
        return true;
    }
}
//清空表格信息
void clearSQL_hotgov()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="delete from hotelgoverns";
    query.prepare(str);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"成功删除";
    }
}

void clearall_hotgov()  //删除表格
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    if(query.exec("drop table hotelgoverns"))
    {
        qDebug()<<"删除成功";
    }
    else qDebug()<<query.lastError();
}
//登录
bool login_hotgov(QString servience,QString passward)
{
    for(int i=0;i<hotgov_List.size();i++)
    {
       if(servience==hotgov_List.at(i)->getservience()&&passward==hotgov_List.at(i)->getpassward())
       {
           return true;
       }
    }
    return false;
}
//注册
bool register_hotgov(QString servience, QString passward, QString name)
{
for(int i=0;i<hotgov_List.size();i++)
{
    if(passward==hotgov_List.at(i)->getpassward())
    {
        return false;
    }
}
hotelgovern *gov=new hotelgovern(servience,passward,name);
hotgov_List.append(gov);
insertSQL_hotgov(servience,passward,name);
close_hotgov();//断开与数据库的连接
return true;
}
void showtable_hotgov()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from hotelgoverns");
    while(query.next())
    {
        qDebug() << query.value(0).toString()
                 << query.value(1).toString()
                 << query.value(2).toString();
    }
}
//更新数据库
bool update_hotgov()          //因为客房变更较多，有删加记录，不易判断改变的索引，因此实现的是清空表格然后从容器中重新读入
{
    if(Connect_hotgov())
    {
        if(judgetable_hotgov())
        {
         clearSQL_hotgov();
         for(int i=0;i<hotgov_List.size();i++)
         {
             insertSQL_hotgov(hotgov_List.at(i)->getservience(),hotgov_List.at(i)->getpassward(),hotgov_List.at(i)->getname());
         }
         close_hotgov();
         return true;
        }
        else
        {
            createTable_hotgov();
            for(int i=0;i<hotgov_List.size();i++)
            {
                insertSQL_hotgov(hotgov_List.at(i)->getservience(),hotgov_List.at(i)->getpassward(),hotgov_List.at(i)->getname());
            }
        close_hotgov();
        return true;
        }
    }
    else return false;
}
//断开连接
void close_hotgov()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    database.close();
    qDebug()<<"断开成功";
}
//将表格中信息读入容器中
//同步初始化酒店的四类客房和酒店管理员对象
void read_hotgov()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from hotelgoverns");
    while(query.next())
    {
    QString servience=query.value(0).toString();
    QString passward=query.value(1).toString();
    QString name=query.value(2).toString();
    hotelgovern *gov=new hotelgovern(servience,passward,name);
    hotgov_List.append(gov);
    }
}
