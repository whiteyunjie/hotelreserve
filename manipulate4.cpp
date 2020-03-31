#include "manipulate4.h"

bool Connect_room()
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
bool createTable_room()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    bool jud=query.exec("create table rooms(type varchar(20),belongname varchar(30),roomphotoadd varchar(30),roomnum int,vacanynum int,"
                        "price int,discount float)");
    if(!jud)
    {
        qDebug()<<"创建失败"<<query.lastError();
        return false;
    }
    else return true;
}

bool judgetable_room() //判断表格是否存在
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    return database.tables().contains("rooms");
}
bool insertSQL_room(QString type, QString belongname,QString roomphotoadd,int roomnum,int vacanynum,int price,float discount)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="insert into rooms values (?,?,?,?,?,?,?)";
    query.prepare(str);
    query.addBindValue(type);
    query.addBindValue(belongname);
    query.addBindValue(roomphotoadd);
    query.addBindValue(roomnum);
    query.addBindValue(vacanynum);
    query.addBindValue(price);
    query.addBindValue(discount);
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
void clearSQL_room()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="delete from rooms";
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

void clearall_room()  //删除表格
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    if(query.exec("drop table rooms"))
    {
        qDebug()<<"删除成功";
    }
    else qDebug()<<query.lastError();
}

//输出表格中信息
void showtable_room()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from rooms");
    while(query.next())
    {
        qDebug() << query.value(0).toString()
                 << query.value(1).toString()
                 << query.value(2).toString()
                 << query.value(3).toInt()
                 << query.value(4).toInt()
                 << query.value(5).toInt()
                 << query.value(6).toFloat();
    }
}
//断开连接
void close_room()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    database.close();
    qDebug()<<"断开成功";
}
//将表格中信息读入容器中
//同步初始化酒店的四类客房和酒店管理员对象
void read_room()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from rooms");
    while(query.next())
    {
    QString type=query.value(0).toString();
    QString belongname=query.value(1).toString();
    QString roomphotoadd=query.value(2).toString();
    int roomnum=query.value(3).toInt();
    int vacanyroom=query.value(4).toInt();
    int price=query.value(5).toInt();
    float discount=query.value(6).toFloat();
    guestroom *room=new guestroom(type,belongname,roomphotoadd,roomnum,vacanyroom,price,discount);
    room_List.append(room);
    }
}

//更新数据库
bool update_room()          //因为客房变更较多，有删加记录，不易判断改变的索引，因此实现的是清空表格然后从容器中重新读入
{
    if(Connect_room())
    {
        if(judgetable_room())
        {
         clearSQL_room();
         for(int i=0;i<room_List.size();i++)
         {
             insertSQL_room(room_List.at(i)->gettype(),room_List.at(i)->gethotelname(),room_List.at(i)->getroomphototadd(),room_List.at(i)->getroomnum(),
                            room_List.at(i)->getvacanynum(),room_List.at(i)->getprice(),room_List.at(i)->getdiscount());
         }
         close_room();
         return true;
        }
        else
        {
            createTable_room();
            for(int i=0;i<room_List.size();i++)
            {
                insertSQL_room(room_List.at(i)->gettype(),room_List.at(i)->gethotelname(),room_List.at(i)->getroomphototadd(),room_List.at(i)->getroomnum(),
                               room_List.at(i)->getvacanynum(),room_List.at(i)->getprice(),room_List.at(i)->getdiscount());
            }
        close_room();
        return true;
        }
    }
    else return false;
}
 //程序运行结束时释放掉内存
 void delete_room()
 {
   qDeleteAll(room_List);
   room_List.clear();
}
