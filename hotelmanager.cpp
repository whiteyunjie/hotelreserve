#include "hotelmanager.h"

QString hotelmanager::gethotpassward()
{
    return hotpassward;
}

QString hotelmanager::getservicelience()
{
    return servicelience;
}

void hotelmanager::setpass(QString pass)
{
    hotpassward=pass;
}

void hotelmanager::changeauthority()
{
    if(authority) authority=false;
    else authority=true;
}

bool hotelmanager::getauthority()
{
    return authority;
}

QString hotelmanager::authtransfer()
{
    if(authority) return "通过";
    else return "未通过";
}
