#include "roominformation.h"
#include "ui_roominformation.h"

roominformation::roominformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roominformation)
{
    ui->setupUi(this);
    data=-1;
}

roominformation::~roominformation()
{
    delete ui;
}

void roominformation::getdata(int m)
{
    QVector<int> roomindex;   //建立一个vector数组记录客房中所有属于该酒店的客房索引
    for(int i=0;i<room_List.size();i++)
    {
        if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
        {
            roomindex.append(i);
        }
    }
    if(room_List.size())
    {
      ui->roomdis->setText(QString("%1").arg(room_List.at(roomindex[m])->getdiscount()));
      ui->roomnumm->setText(QString("%1").arg(room_List.at(roomindex[m])->getroomnum()));
      ui->roomprice->setText(QString("%1").arg(room_List.at(roomindex[m])->getprice()));
      ui->roomtype->setText(room_List.at(roomindex[m])->gettype());
      ui->roompic->setText((room_List.at(roomindex[m])->getroomphototadd()));
    }
    roomindex.clear();
    data=m;
}

void roominformation::on_roomsure_clicked()
{
    if(data==-1)
    {
        QString roomphoto;
        if(ui->roompic->text().isEmpty())
        {
            roomphoto="无";
        }
        else roomphoto=ui->roompic->text();
        QString type=ui->roomtype->text();
        QString hotelname=hot_List.at(hotelposition)->gethotelname();
        int roomnum=ui->roomnumm->text().toInt();
        int roomvacany=roomnum;
        int roomprice=ui->roomprice->text().toInt();
        float discount=ui->roomdis->text().toFloat();
        guestroom *room=new guestroom(type,hotelname,roomphoto,roomnum,roomvacany,roomprice,discount);
        room_List.append(room);
        QMessageBox::information(this,"信息提示","成功",QMessageBox::Ok);
        update_room();
        showtable_room();
    }
    else
    {
        QVector<int> roomindex;   //建立一个vector数组记录客房中所有属于该酒店的客房索引
        QString roomphoto;
        for(int i=0;i<room_List.size();i++)
        {
            if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
            {
                roomindex.append(i);
            }
        }
        if(ui->roompic->text().isEmpty())
        {
            roomphoto="无";
        }
        else roomphoto=ui->roompic->text();
        room_List.at(roomindex[data])->settype(ui->roomtype->text());
        room_List.at(roomindex[data])->setdiscount(ui->roomdis->text());
        room_List.at(roomindex[data])->setprice(ui->roomprice->text());
        room_List.at(roomindex[data])->setroomnum(ui->roomnumm->text()); //该函数也会顺便修改空房数量
        room_List.at(roomindex[data])->setroomphotoadd(roomphoto);
        QMessageBox::information(this,"信息提示","成功",QMessageBox::Ok);
    roomindex.clear();
    }
    emit upup();
    this->close();
}

void roominformation::on_roomback_clicked()
{
    this->close();
}
