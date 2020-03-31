#include "cuschangeinfo.h"
#include "ui_cuschangeinfo.h"

cuschangeinfo::cuschangeinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cuschangeinfo)
{
    ui->setupUi(this);
    this->setWindowTitle("信息修改");
    ui->name->setText(cus_List.at(customerposition)->getname());
    ui->identityid->setText(cus_List.at(customerposition)->getidentityid());
    ui->passward->setText(cus_List.at(customerposition)->getpassward());
    ui->telephone->setText(cus_List.at(customerposition)->getiphonenum());
}

cuschangeinfo::~cuschangeinfo()
{
    delete ui;
}

void cuschangeinfo::on_change_clicked()
{
    bool flag=true;
    int i;
    cus_List.at(customerposition)->setname(ui->name->text());
    cus_List.at(customerposition)->setpassward(ui->passward->text());
    //重新显示即可
    ui->setupUi(this);
    ui->name->setText(cus_List.at(customerposition)->getname());
    ui->identityid->setText(cus_List.at(customerposition)->getidentityid());
    ui->passward->setText(cus_List.at(customerposition)->getpassward());
    ui->telephone->setText(cus_List.at(customerposition)->getiphonenum());
    for(i=0;cuschange[i]>-1;i++)
    {
        if(cuschange[i]==customerposition)
        {
            flag=false;
            break;
        }
    }
    if(flag) cuschange[i]=customerposition;
}

void cuschangeinfo::on_pushButton_2_clicked()
{
    this->close();
}
