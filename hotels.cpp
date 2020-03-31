#include "hotels.h"
#include <QDebug>


QString hotels::gethotelname()
{
    return hotelname;
}

QString hotels::getaddress()
{
    return address;
}

QString hotels::gettelephone()
{
    return telephone;
}

QString hotels::getpohotadd()
{
    return photoadd;
}
float hotels::getjudge()
{
    return judge;
}

void hotels::setname(QString name)
{
    hotelname=name;
}
void hotels::setaddress(QString add)
{
    address=add;
}
void hotels::settele(QString tele)
{
    telephone=tele;
}

void hotels::calculate(float j)
{
    peopleass++;
    judge=(judge+j)/peopleass;
}

int hotels::getpeople()
{
    return peopleass;
}

void hotels::setphotoadd(QString ad)
{
    photoadd=ad;
}

QString hotels::getcity()
{
    return city;
}

int hotels::getminiprice()
{
    return minprice;
}

void hotels::setminiprice(int pr)
{
    minprice=pr;
}
