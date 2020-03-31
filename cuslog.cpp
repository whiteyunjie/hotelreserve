#include "cuslog.h"
#include "ui_cuslog.h"
#include "manipulatesql.h"

cuslog::cuslog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cuslog)
{
    ui->setupUi(this);
    this->setWindowTitle("客户登录");
}

cuslog::~cuslog()
{
    delete ui;
}
void cuslog::s_cuslog()
{
    this->exec();
}

void cuslog::on_pushButton_clicked()
{
    QString iphonenum=ui->iphonenum->text();
    QString passward=ui->passward->text();
    int p;
    for(int i=0;i<cus_List.size();i++)
    {
        qDebug()<<cus_List.at(i)->getname();
    }
    Connect_cus();
    if(!cus_List.size())
    {
    read_cus();
    }
    if(!ord_List.size())
    {
        read_ord();
    }
    if(!hot_List.size())
    {
        read_hot();
    }
    if(!room_List.size())
    {
        read_room();
    }
    close_cus();
    p=login_cus(iphonenum,passward);
    if(p==-1)
    {
        QMessageBox::information(this,"信息提示","用户或密码错误",QMessageBox::Ok);
        ui->iphonenum->clear();
        ui->passward->clear();
    }
    else
    {
        customerposition=p;
        QMessageBox::information(this,"信息提示","登录成功",QMessageBox::Ok);
        hotelreserve hs;
        ui->iphonenum->clear();
        ui->passward->clear();
        this->close();
        hs.exec();
    }
}
