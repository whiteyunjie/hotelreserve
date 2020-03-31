#include "hotreg.h"
#include "ui_hotreg.h"
#include "manipulate3.h"
#include "hotelwindow.h"
#include "manipulate4.h"

hotreg::hotreg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotreg)
{
    ui->setupUi(this);
    this->setWindowTitle("酒店注册");
}

hotreg::~hotreg()
{
    delete ui;
}

void hotreg::s_hotreg()
{
    this->exec();
}

void hotreg::on_hotregister_clicked()
{
    QString hotelname=ui->hotelname->text();
    QString address=ui->address->text();
    QString city=ui->city->text();
    QString servicelience=ui->servicelience->text();
    QString hotiphone=ui->hotiphone->text();
    QString hotpassward=ui->hotpassward->text();
    int p;
    if(Connect_hot())
    {
        if(!judgetable_hot())
        {
            createTable_hot();
            if(!judgetable_room())
            {
                 createTable_room();
                 if(ord_List.size())
                 {
                     read_ord();
                 }
                 p=register_hot(hotelname,servicelience,address,city,hotiphone,hotpassward);
                 if(p!=-1)
                 {
                 QMessageBox::information(this,"信息提示","注册成功",QMessageBox::Ok);
                 ui->hotelname->clear();
                 ui->address->clear();
                 ui->city->clear();
                 ui->servicelience->clear();
                 ui->hotiphone->clear();
                 ui->hotpassward->clear();
                 hotelposition=p;
                 hotelwindow hw;
                 this->close();
                 hw.exec();
                 }
                 else QMessageBox::information(this,"信息提示","注册失败",QMessageBox::Ok);
            }
        }
        else
        {
            if(!hot_List.size())
            {
            read_hot();
            }
            if(!judgetable_room()) createTable_room();
            if(ord_List.size())
            {
                read_ord();
            }
            if(!room_List.size())
            {
             read_room();
            }
            showtable_hot();
            showtable_room();
            close_hot();
            p=register_hot(hotelname,servicelience,address,city,hotiphone,hotpassward);
            if(p!=-1)
            {
                QMessageBox::information(this,"信息提示","注册成功",QMessageBox::Ok);
                ui->hotelname->clear();
                ui->address->clear();
                ui->city->clear();
                ui->servicelience->clear();
                ui->hotiphone->clear();
                ui->hotpassward->clear();
                hotelposition=p;
                hotchange[0]=0;
                hotelwindow hw;
                this->close();
                hw.exec();
            }
            else QMessageBox::information(this,"信息提示","注册失败",QMessageBox::Ok);
        }
    }
    else qDebug()<<"数据库连接失败";
}

void hotreg::on_hotregback_clicked()
{
    this->close();
}
