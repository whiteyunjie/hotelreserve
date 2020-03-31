#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QObject>

class hotels;

class customers
{
private:
    QString iphonenum;
    QString identityid;
    QString name;
    QString sex;
    QString passward;

public:
    customers(QString iphonenum,QString identityid,QString name,QString sex,QString passward):iphonenum(iphonenum),identityid(identityid),name(name),sex(sex),passward(passward){}
    int judge(const hotels & hotel);
    //订房？？？
    QString getiphonenum();
    QString getidentityid();
    QString getname();
    QString getsex();
    QString getpassward();
    void setname(QString na);
    void setpassward(QString pa);
};

#endif // CUSTOMERS_H
