#ifndef ORDERS_H
#define ORDERS_H

#include <QObject>
#include <QDate>

class orders
{
public:
    orders(QString cusname,QString cusiphone,QString hotelname,QString hoteladdress,QString situation,QString cusrequest,QString type,QDate reservedate,
           int reservedays,int price,int ordnum):cusname(cusname),cusiphone(cusiphone),hotelname(hotelname),hoteladdress(hoteladdress),
           situation(situation),cusrequest(cusrequest),type(type),reservedate(reservedate),reservedays(reservedays),price(price),ordnum(ordnum){}
    void changesit(QString after);// 参数是订单更改之后的状态
    QString getcusiphone();
    QString getcusname();
    QString gethotelname();
    QString getaddress();
    QString getsituation();
    QString getcusreq();   //得到顾客请求
    QDate getdate();
    void setprice(float dis,int pri);  //通过日单价、天数和折扣计算价格
    QString gettype();
    int getprice();
    int getordnum();
    void setordnum(int s);
    void setdays(int d);
    int getdays();
    void changerequest(QString req);
    void sethotelname(QString hot);
private:
    QString cusname;
    QString cusiphone;
    QString hotelname;
    QString hoteladdress;
    QString situation;      //订单状态有四种，分别是已付款（未经酒店接单），未入住，已入住，订单完成
    QString cusrequest;     //顾客的申请操作，有无要求，申请入住，申请退款，申请退房，酒店通过对这些要求的操作实现订单状态的转变
    QString type;
    QDate reservedate;   //顾客下单的日期
    int reservedays;   //顾客预订的入住天数
    int price;
    int ordnum;
};

#endif // ORDERS_H
