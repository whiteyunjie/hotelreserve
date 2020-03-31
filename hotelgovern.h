#ifndef HOTELGOVERN_H
#define HOTELGOVERN_H

#include <QObject>

class hotelgovern
{
private:
    QString servience;
    QString passward;
    QString name;
public:
    hotelgovern(QString servience,QString passward,QString name):servience(servience),passward(passward),name(name){}
    QString getpassward();
    QString getservience();
    QString getname();
};

#endif // HOTELGOVERN_H
