#include "manipulate3.h"

bool Connect_hot()
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
bool createTable_hot()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    bool jud=query.exec("create table hotels(servicelience varchar(20),address varchar(30),city varchar(20),"
                "hotelname varchar(30),telephone varchar(30),hotpassward varchar(20),photoadd varchar(30),"
                        "authority bool,judge float,peopleass int,minprice int)");
    if(!jud)
    {
        qDebug()<<"创建失败"<<query.lastError();
        return false;
    }
    else return true;
}

bool judgetable_hot() //判断表格是否存在
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    return database.tables().contains("hotels");
}
bool insertSQL_hot(QString servicelience, QString address, QString city, QString hotelname, QString telephone, QString hotpassward, QString photoadd,
                   bool authority, float jud, int peopleass, int minprice) //与注册界面顺序一样，插入数据，即注册用户
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="insert into hotels values (?,?,?,?,?,?,?,?,?,?,?)";
    query.prepare(str);
    query.addBindValue(servicelience);
    query.addBindValue(address);
    query.addBindValue(city);
    query.addBindValue(hotelname);
    query.addBindValue(telephone);
    query.addBindValue(hotpassward);
    query.addBindValue(photoadd);
    query.addBindValue(authority);
    query.addBindValue(jud);
    query.addBindValue(peopleass);
    query.addBindValue(minprice);
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
bool selectSQL_hot(QString servicelience,QString hotpassward)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str=QString("select * from hotels where ='%1' and passward='%2'").arg(servicelience).arg(hotpassward);
    query.exec(str);
    query.last();
    int record=query.at()+1;
    if(record==0) return false;
    return true;
}


//清空表格信息
void clearSQL_hot()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str="delete from hotels";
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

void clearall_hot()  //删除表格
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    if(query.exec("drop table hotels"))
    {
        qDebug()<<"删除成功";
    }
    else qDebug()<<query.lastError();
}
//删除某一条
void clear_hot(QString servicelience)
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    QString str=QString("delete from hotels where servicelience = %1").arg(servicelience);
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
void showtable_hot()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from hotels");
    while(query.next())
    {
        qDebug() << query.value(0).toString()
                 << query.value(1).toString()
                 << query.value(2).toString()
                 << query.value(3).toString()
                 << query.value(4).toString()
                 << query.value(5).toString()
                 << query.value(6).toString()
                 << query.value(7).toBool()
                 << query.value(8).toFloat()
                 << query.value(9).toInt();
    }
}
//断开连接
void close_hot()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    database.close();
    qDebug()<<"断开成功";
}
//将表格中信息读入容器中
//同步初始化酒店的四类客房和酒店管理员对象
void read_hot()
{
    QSqlDatabase database=QSqlDatabase::database("sqlite1");
    QSqlQuery query(database);
    query.exec("select * from hotels");
    while(query.next())
    {
    QString servicelience=query.value(0).toString();
    QString address=query.value(1).toString();
    QString city=query.value(2).toString();
    QString hotelname=query.value(3).toString();
    QString telephone=query.value(4).toString();
    QString hotpassward=query.value(5).toString();
    QString photoadd=query.value(6).toString();
    bool authority=query.value(7).toBool();
    float judge=query.value(8).toFloat();
    int peopleass=query.value(9).toInt();
    int minprice=query.value(10).toInt();
    hotels *hotel=new hotels(address,city,hotelname,telephone,photoadd,judge,peopleass,minprice);
    hot_List.append(hotel);
    hotelmanager *hotelman=new hotelmanager(servicelience,hotpassward,authority);
    hotman_List.append(hotelman);
    }
}
//注册
int register_hot(QString hotelname,QString servicelience, QString address, QString city, QString telephone, QString hotpassward)
{
for(int i=0;i<hotman_List.size();i++)
{
    if(servicelience==hotman_List.at(i)->getservicelience()||hotelname==hot_List.at(i)->gethotelname())
    {
        return -1;
    }
}
hotels *hotel=new hotels(address,city,hotelname,telephone,NULL,0.0,0,0);
hot_List.append(hotel);
hotelmanager *hotelman=new hotelmanager(servicelience,hotpassward,false);
hotman_List.append(hotelman);
return hot_List.size()-1;
}

//登录
int login_hot(QString servicelience,QString hotpassward)
{
for(int i=0;i<hotman_List.size();i++)
{
    if(servicelience==hotman_List.at(i)->getservicelience()&&hotpassward==hotman_List.at(i)->gethotpassward())
    {
        return i;  //获得本次登录的酒店位于容器的索引，其和酒店管理员的索引是一样的
    }
}
 return -1;
 }

//更新数据库
bool update_hot()
{
    if(hotchange[0]==-1){close_hot();return true;}
    else
    {
        for(int i=0;hotchange[i]>-1;i++)
        {
            if(Connect_hot())
            {
                if(judgetable_hot())
                {
                    clear_hot(hotman_List.at(hotchange[i])->getservicelience());
                    insertSQL_hot(hotman_List.at(hotchange[i])->getservicelience(),hot_List.at(hotchange[i])->getaddress(),
                                  hot_List.at(hotchange[i])->getcity(),hot_List.at(hotchange[i])->gethotelname(),
                                  hot_List.at(hotchange[i])->gettelephone(),hotman_List.at(hotchange[i])->gethotpassward(),
                                  hot_List.at(hotchange[i])->getpohotadd(),hotman_List.at(hotchange[i])->getauthority(),
                                  hot_List.at(hotchange[i])->getjudge(),hot_List.at(hotchange[i])->getpeople(),
                                  hot_List.at(hotchange[i])->getminiprice());
                }
            else
                {
                    if(!createTable_hot()) return false;
                    insertSQL_hot(hotman_List.at(hotchange[i])->getservicelience(),hot_List.at(hotchange[i])->getaddress(),
                                  hot_List.at(hotchange[i])->getcity(),hot_List.at(hotchange[i])->gethotelname(),
                                  hot_List.at(hotchange[i])->gettelephone(),hotman_List.at(hotchange[i])->gethotpassward(),
                                  hot_List.at(hotchange[i])->getpohotadd(),hotman_List.at(hotchange[i])->getauthority(),
                                  hot_List.at(hotchange[i])->getjudge(),hot_List.at(hotchange[i])->getpeople(),
                                  hot_List.at(hotchange[i])->getminiprice());
                }
            }
        else return false;
        }
    }
    close_hot();
    return true;
}
 //程序运行结束时释放掉内存
 void delete_hot()
 {
   qDeleteAll(hot_List);
   hot_List.clear();
   qDeleteAll(hotman_List);
   hotman_List.clear();
}
