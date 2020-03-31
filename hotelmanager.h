#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H

#include <QObject>

class hotelmanager               //酒店管理者类主要处理登录，不在包含酒店和客房，需要时直接从两个类操作即可，其数据信息与酒店存在数据库同一张表格中
{
private:
    QString servicelience;
    QString hotpassward;
    bool authority;  //酒店获得权限后才能在用户的预订界面上出现
public:
    hotelmanager(QString servicelience,QString hotpassward,bool authority):servicelience(servicelience),hotpassward(hotpassward),authority(authority){}
    QString getservicelience();
    QString gethotpassward();
    void setpass(QString pass);  //设置密码修改密码
    void changeauthority();  //平台在处理权限是可以调用
    bool getauthority();
    QString authtransfer();  //将权限以字符串形式返回以便在表格中显示
};

#endif // HOTELMANAGER_H
