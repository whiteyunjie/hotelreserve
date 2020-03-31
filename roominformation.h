#ifndef ROOMINFORMATION_H
#define ROOMINFORMATION_H

#include <QDialog>
#include <QList>
#include <QVector>
#include <QMessageBox>
#include "hotels.h"
#include "guestroom.h"
#include "manipulate4.h"
#include "manipulate3.h"
extern QList<hotels *> hot_List;
extern QList<guestroom *> room_List;
extern int hotelposition;
namespace Ui {
class roominformation;
}

class roominformation : public QDialog
{
    Q_OBJECT

public:
    explicit roominformation(QWidget *parent = 0);
    ~roominformation();
    void getdata(int m);

private slots:
    void on_roomsure_clicked();

    void on_roomback_clicked();
signals:
    void upup();

private:
    Ui::roominformation *ui;
    int data;  //获得所点的行的行数
};

#endif // ROOMINFORMATION_H
