#include "hotupdate.h"
#include "ui_hotupdate.h"
#include "manipulate3.h"

hotupdate::hotupdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotupdate)
{
    ui->setupUi(this);
    this->setWindowTitle("修改信息");
    ui->address->setText(hot_List.at(hotelposition)->getaddress());
    ui->name->setText(hot_List.at(hotelposition)->gethotelname());
    ui->telephone->setText(hot_List.at(hotelposition)->gettelephone());
    ui->passward->setText(hotman_List.at(hotelposition)->gethotpassward());
}

hotupdate::~hotupdate()
{
    delete ui;
}

void hotupdate::updatehotinfo()
{
    QVector<int> roomindex;   //建立一个vector数组记录客房中所有属于该酒店的客房索引
    for(int i=0;i<room_List.size();i++)
    {
        if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
        {
            roomindex.append(i);
        }
    }
    QList<orders *> ordhot_List;
    for(int i=0;i<ord_List.size();i++)
    {
        if(ord_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname()) ordhot_List.append(ord_List.at(i));
    }
    hot_List.at(hotelposition)->setaddress(ui->address->text());
    hot_List.at(hotelposition)->setname(ui->name->text());
    hot_List.at(hotelposition)->settele(ui->telephone->text());
    hot_List.at(hotelposition)->setphotoadd(ui->hotelphotoadd->text());
    hotman_List.at(hotelposition)->setpass(ui->passward->text());
    for(int i=0;i<ordhot_List.size();i++)   //订单的酒店名也随之更改
    {
        ordhot_List.at(i)->sethotelname(ui->name->text());
    }
    for(int i=0;i<roomindex.size();i++)       //房间所属酒店名也要更改
    {
        room_List.at(roomindex[i])->setbelong(ui->name->text());
    }
    //刷新界面
    ui->address->setText(hot_List.at(hotelposition)->getaddress());
    ui->name->setText(hot_List.at(hotelposition)->gethotelname());
    ui->telephone->setText(hot_List.at(hotelposition)->gettelephone());
    ui->passward->setText(hotman_List.at(hotelposition)->gethotpassward());
    ui->hotelphotoadd->setText(hot_List.at(hotelposition)->getpohotadd());
    int i;
    bool flag=true;
    for(i=0;hotchange[i]>-1;i++)
    {
        if(hotchange[i]==hotelposition)
        {
            flag=false;
            break;
        }
    }
    if(flag) hotchange[i]=hotelposition;
}

void hotupdate::on_hotchange_clicked()
{
    updatehotinfo();
    emit uphothot();
    this->close();
}


void hotupdate::on_changebck_clicked()
{
    this->close();
}
