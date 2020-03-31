#include "customers.h"

QString customers::getidentityid()
{
    return identityid;
}


QString customers::getiphonenum()
{
    return iphonenum;
}

QString customers::getname()
{
    return name;
}

QString customers::getpassward()
{
    return passward;
}

QString customers::getsex()
{
    return sex;
}

void customers::setname(QString na)
{
    name=na;
}

void customers::setpassward(QString pa)
{
    passward=pa;
}
