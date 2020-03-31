#include "orders.h"

void orders::changesit(QString after)
{
    situation=after;
}

QString orders::getsituation()
{
    return situation;
}

QString orders::getcusiphone()
{
    return cusiphone;
}

QString orders::getaddress()
{
    return hoteladdress;
}

QDate orders::getdate()
{
    return reservedate;
}
QString orders::getcusname()
{
    return cusname;
}

QString orders::gethotelname()
{
    return hotelname;
}

int orders::getprice()
{
   return price;
}

QString orders::gettype()
{
    return type;
}

void orders::setprice(float dis,int pri)
{
    price=pri*reservedays*dis/10;
}

QString orders::getcusreq()
{
    return cusrequest;
}

int orders::getordnum()
{
    return ordnum;
}

void orders::setordnum(int s)  //传进来的参数是长度
{
    ordnum=s-1;
}

int orders::getdays()
{
    return reservedays;
}

void orders::setdays(int d)
{
    reservedays=d;
}

void orders::changerequest(QString req)
{
    cusrequest=req;
}

void orders::sethotelname(QString hot)
{
    hotelname=hot;
}
