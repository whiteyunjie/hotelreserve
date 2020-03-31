#ifndef HOTELS_H
#define HOTELS_H

#include "guestroom.h"
#include <QObject>
#include <QVector>


class hotels
{
private:                                     //客房和酒店是松耦合关系，如果作为酒店成员无法实现动态添加客房类型
    QString address;
    QString city;   //酒店所在城市，以便顾客在界面上搜索
    QString hotelname;
    QString telephone;
    QString photoadd;  //酒店上传的图片地址
    float judge; //酒店评分（初始值为零表示还没有评分）
    int peopleass;//对酒店评过分的总人数，以便计算酒店评分
    int minprice;  //酒店以多少元的价格起，用于价格排序
public:
    hotels(QString add,QString city,QString hotelname,QString telephone,QString photoadd,float jud,int peopleass,int minprice):address(add),city(city),
        hotelname(hotelname),telephone(telephone),photoadd(photoadd),judge(jud),peopleass(peopleass),minprice(minprice){}
    //其他操作有酒店管理员实现（什么作用？）
    QString gethotelname();
    QString gettelephone();
    QString getaddress();
    QString getpohotadd();
    QString getcity();
    float getjudge();
    int getminiprice();
    void setminiprice(int pr);
    void setname(QString name);    //用于修改信息的函数
    void settele(QString tele);
    void setaddress(QString add);
    void setphotoadd(QString ad);
    void calculate(float j);//通过用户打的分数重新计算评分
    int getpeople();  //得到评分人数
};

#endif // HOTELS_H
