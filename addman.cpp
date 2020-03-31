#include "addman.h"
#include "ui_addman.h"

addman::addman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addman)
{
    ui->setupUi(this);
    this->setWindowTitle("增加管理员");
}

addman::~addman()
{
    delete ui;
}

void addman::on_sure_clicked()
{
   QString pas=ui->pas->text();
   QString name=ui->name->text();
   if(Connect_hotgov())
   {
       if(judgetable_hotgov())
       {
           if(register_hotgov(hotman_List.at(hotelposition)->getservicelience(),pas,name))
           {
               QMessageBox::information(this,"信息提示","增加成功",QMessageBox::Ok);
               showtable_hotgov();
           }
           else
           {
               QMessageBox::information(this,"信息提示","失败",QMessageBox::Ok);
           }
       }
       else
       {
           if(createTable_hotgov())
           {
               insertSQL_hotgov(hotman_List.at(hotelposition)->getservicelience(),pas,name);
               QMessageBox::information(this,"信息提示","增加成功",QMessageBox::Ok);
           }
       }
   close_hotgov();
   }
   emit govtable();
   this->close();
}

void addman::on_pushButton_clicked()
{
    this->close();
}
