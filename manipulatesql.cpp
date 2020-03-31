#include "manipulatesql.h"

bool Connect_cus()
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
bool createTable_cus()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    bool jud=query.exec("create table customers(iphonenum varchar(20),"
                "identityid varchar(30),name varchar(30),sex varchar(10),passward varchar(30))");
    if(!jud)
    {
        qDebug()<<"创建失败"<<query.lastError();
        return false;
    }
    else return true;
}

bool judgetable_cus() //判断表格是否存在
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.next();
    return database.tables().contains("customers");
}
int insertSQL_cus(QString iphonenum,QString identityid, QString name, QString sex, QString passward) //与注册界面顺序一样，插入数据，即注册用户
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="insert into customers values (?,?,?,?,?)";
    query.prepare(str);
    query.addBindValue(iphonenum);
    query.addBindValue(identityid);
    query.addBindValue(name);
    query.addBindValue(sex);
    query.addBindValue(passward);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
        return false;
    }
    else{
        return true;
    }
}
//判断是否存在该用户
bool selectSQL_cus(QString iphonenum,QString passward)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str=QString("select * from customers where iphonenum='%1' and passward='%2'").arg(iphonenum).arg(passward);
    query.exec(str);
    query.last();
    int record=query.at()+1;
    if(record==0) return false;
    return true;
}

bool update_cus(QString passward,QString iphonenum)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str=QString("update customers set passward = %1 where iphonenum = %2").arg(passward).arg(iphonenum);
    if(!query.exec(str))
    {
        qDebug()<<"更新失败"<<query.lastError();
        return false;
    }
    return true;
}
//清空表格信息
void clearSQL_cus()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="delete from customers";
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

void clear_onecus(QString name)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str=QString("delete from customers where name = %1").arg(name);
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
//输出表格中信息
void showtable_cus()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from customers");
    while(query.next())
    {
        qDebug() << query.value(0).toString()
                 << query.value(1).toString()
                 << query.value(2).toString()
                 << query.value(3).toString()
                 << query.value(4).toString();
    }
}
//断开连接
void close_cus()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    database.close();
}
//将表格中信息读入容器中
void read_cus()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from customers");
    while(query.next())
    {
    QString iphonenum=query.value(0).toString();
    QString identityid=query.value(1).toString();
    QString name=query.value(2).toString();
    QString sex=query.value(3).toString();
    QString passward=query.value(4).toString();
    customers *customer=new customers(iphonenum,identityid,name,sex,passward);
    cus_List.append(customer);
    }
}
//注册
int register_cus(QString iphonenum,QString identityid, QString name, QString sex, QString passward)
{
for(int i=0;i<cus_List.size();i++)
{
    if(iphonenum==cus_List.at(i)->getiphonenum()||identityid==cus_List.at(i)->getidentityid())
    {
        return -1;
    }
}
customers *cus=new customers(iphonenum,identityid,name,sex,passward);
cus_List.append(cus);
insertSQL_cus(iphonenum,identityid,name,sex,passward);  //后续不会更改客户信息，所以在此处修改数据库数据
close_cus();//断开与数据库的连接
return cus_List.size()-1;
}

//登录
int login_cus(QString iphonenum,QString passward)
{
for(int i=0;i<cus_List.size();i++)
{
   if(iphonenum==cus_List.at(i)->getiphonenum()&&passward==cus_List.at(i)->getpassward())
   {
       return i;
   }
}
return -1;
}

//更新数据库
bool updatesql_cus()
{
    if(cuschange[0]==-1) close_cus();
    else
    {
        for(int i=0;cuschange[i]>-1;i++)
        {
            if(Connect_cus())
            {
                 if(!update_cus(cus_List.at(cuschange[i])->getpassward(),cus_List.at(cuschange[i])->getiphonenum())) return false;
            }
            else return false;
        }
    }
close_cus();
return true;
}


//程序运行结束时释放掉内存
void delete_cus()
{
   qDeleteAll(cus_List);
   cus_List.clear();
}
