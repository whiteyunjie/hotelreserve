#include "manipulate2.h"


//连接或创建数据库
bool Connect_ord()
{
    QSqlDatabase database;
    if(QSqlDatabase::contains("sqlite1")) database=QSqlDatabase::database("sqlite1");  //同样用之前的连接名
    else
    {
        database=QSqlDatabase::addDatabase("QSQLITE","sqlite1");
        database.setDatabaseName("hotelreservation.db");   //专门储存订单
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

//创建表格
bool createTable_ord()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    bool jud=query.exec("create table orders(cusname varchar(20),"
                "cusiphone varchar(30),hotelname varchar(30),hoteladdress varchar(30),"
                "situation varchar(20),cusrequest varchar(30),type varchar(30),reservedate date,reservedays int,price int,ordnum int)");
    if(!jud)
    {
        qDebug()<<"创建失败"<<query.lastError();
        return false;
    }
    else return true;
}

bool judgetable_ord() //判断表格是否存在
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    return database.tables().contains("orders");
}
bool insertSQL_ord(QString cusname,QString cusiphone,QString hotelname,QString hoteladdress,QString situation,QString cusrequest,QString type,
                   QDate reservedate,int reservedays,int price,int ordnum) //插入数据到数据库
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="insert into orders values (?,?,?,?,?,?,?,?,?,?,?)";
    query.prepare(str);
    query.addBindValue(cusname);
    query.addBindValue(cusiphone);
    query.addBindValue(hotelname);
    query.addBindValue(hoteladdress);
    query.addBindValue(situation);
    query.addBindValue(cusrequest);
    query.addBindValue(type);
    query.addBindValue(reservedate);
    query.addBindValue(reservedays);
    query.addBindValue(price);
    query.addBindValue(ordnum);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
        return false;
    }
    else{
        return true;
    }
}
//删除某一条
void clear_ord(int ordnum)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString ord=QString::number(ordnum);
    QString str=QString("delete from orders where ordnum = %1").arg(ord);
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

//清空表格信息
void clearSQL_ord()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="delete from orders";
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
void showtable_ord()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from orders");
    while(query.next())
    {
        qDebug() << query.value(0).toString()
                 << query.value(1).toString()
                 << query.value(2).toString()
                 << query.value(3).toString()
                 << query.value(4).toString()
                 << query.value(5).toString()
                 << query.value(6).toString()
                 << query.value(7).toDate()
                 << query.value(8).toInt()
                 << query.value(9).toInt()
                 << query.value(10).toInt();

    }
}

//断开连接
void close_ord()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    database.close();
}
//将表格中信息读入容器中
void read_ord()
{
    Connect_ord();
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from orders");
    while(query.next())
    {
    QString cusname=query.value(0).toString();
    QString cusiphone=query.value(1).toString();
    QString hotelname=query.value(2).toString();
    QString hoteladdress=query.value(3).toString();
    QString situation=query.value(4).toString();
    QString cusrequest=query.value(5).toString();
    QString type=query.value(6).toString();
    QDate reservedate=query.value(7).toDate();
    int reservedays=query.value(8).toInt();
    int price=query.value(9).toInt();
    int ordnum=query.value(10).toInt();
    orders *order=new orders(cusname,cusiphone,hotelname,hoteladdress,situation,cusrequest,type,reservedate,reservedays,price,ordnum);
    ord_List.append(order);
    }
}

//更新数据库
bool update_ord()            //因为客房变更较多，有删加记录，不易判断改变的索引，因此实现的是清空表格然后从容器中重新读入
{
            if(Connect_ord())
            {
                if(judgetable_ord())
                {
                    clearSQL_ord();
                    for(int i=0;i<ord_List.size();i++)
                    {
                    insertSQL_ord(ord_List.at(i)->getcusname(),ord_List.at(i)->getcusiphone(),
                                  ord_List.at(i)->gethotelname(),ord_List.at(i)->getaddress(),
                                  ord_List.at(i)->getsituation(),ord_List.at(i)->getcusreq(),
                                  ord_List.at(i)->gettype(),ord_List.at(i)->getdate(),
                                  ord_List.at(i)->getdays(),ord_List.at(i)->getprice(),ord_List.at(i)->getordnum()); 
                    }
                return true;
                }
               else
                {
                    if(!createTable_ord()) return false;
                    for(int i=0;i<ord_List.size();i++)
                    {
                        insertSQL_ord(ord_List.at(i)->getcusname(),ord_List.at(i)->getcusiphone(),
                                      ord_List.at(i)->gethotelname(),ord_List.at(i)->getaddress(),
                                      ord_List.at(i)->getsituation(),ord_List.at(i)->getcusreq(),
                                      ord_List.at(i)->gettype(),ord_List.at(i)->getdate(),
                                      ord_List.at(i)->getdays(),ord_List.at(i)->getprice(),ord_List.at(i)->getordnum());
                    }
                }
            }
        else return false;
    close_ord();
    return true;
}

//程序运行结束时释放掉内存
void delete_ord()
{
   qDeleteAll(ord_List);
   ord_List.clear();
}
