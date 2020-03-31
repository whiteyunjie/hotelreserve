#include "cusreg.h"
#include "ui_cusreg.h"
#include "manipulatesql.h"

cusreg::cusreg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cusreg)
{
    ui->setupUi(this);
    this->setWindowTitle("客户注册");
}

cusreg::~cusreg()
{
    delete ui;
}

void cusreg::s_cusreg()
{
    this->exec();
}


void cusreg::on_cusclose_clicked()
{
    this->close();
}

void cusreg::on_cusregisiter_clicked()
{
    QString iphonenum=ui->cusiphone->text();
    QString identityid=ui->cusiden->text();
    QString name=ui->cusname->text();
    QString passward=ui->cuspassword->text();
    QString sex;
    int p;
    if(ui->radioButton->isChecked())
    {
        sex=ui->radioButton->text();
    }
    if(ui->radioButton_2->isChecked())
    {
        sex=ui->radioButton_2->text();
    }
    if(Connect_cus())
    {
        if(judgetable_cus())
        {
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
            p=register_cus(iphonenum,identityid,name,sex,passward);
            if(p!=-1)
            {
                QMessageBox::information(this,"信息提示","注册成功!",QMessageBox::Ok);
                hotelreserve hs;//转页面
                ui->cusiphone->clear();
                ui->cusiden->clear();
                ui->cusname->clear();
                ui->cuspassword->clear();
                customerposition=p;
                this->close();
                hs.exec();
            }
            else
            {
                QMessageBox::information(this,"信息提示","注册失败!",QMessageBox::Ok);
            }
            showtable_cus();
        }
        else
        {
            if(createTable_cus())
            {
                bool ok=insertSQL_cus(iphonenum,identityid,name,sex,passward);
                if(ok) QMessageBox::information(this,"信息提示","注册成功!",QMessageBox::Ok);
                customerposition=0;
                hotelreserve hs;
                ui->cusiphone->clear();
                ui->cusiden->clear();
                ui->cusname->clear();
                ui->cuspassword->clear();
                this->close();
                hs.exec();
                showtable_cus();
            }
            else QMessageBox::information(this,"信息提示","注册失败",QMessageBox::No);
        }
    }
    else QMessageBox::information(this,"信息提示","注册失败",QMessageBox::No);
    close_cus();
}
