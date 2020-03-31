#include "platform.h"
#include "ui_platform.h"
#include "platwindow.h"

platform::platform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::platform)
{
    ui->setupUi(this);
    this->setWindowTitle("平台登录");
}

platform::~platform()
{
    delete ui;
}

void platform::s_platlog()
{
    this->exec();
}

void platform::on_reg_plat_clicked()
{
    QString id=ui->plat_id->text();
    QString platpassward=ui->passward_plat->text();
    if(Connect_hot())
    {
        if(judgetable_hot())
        {

            if(!hot_List.size())
            {
            read_hot();   //读入酒店信息
            qDebug()<<"读入成功";
            close_hot();
        }
        }
    }
    if(Connect_cus())
    {
        if(judgetable_hot())
        {
            if(!cus_List.size())
            {
            read_cus();   //读入酒店信息
            qDebug()<<"读入成功";
            close_cus();
            }
        }
    }
    if(Connect_plat())
    {
        if(judgetable_plat())
        {
            if(selectSQL_plat(id,platpassward))
            {
                QMessageBox::information(this,"信息提示","登录成功",QMessageBox::Ok);
                platwindow pw;
                this->close();
                pw.exec();
            }
            else
            {
                QMessageBox::information(this,"信息提示","用户名或密码错误",QMessageBox::Ok);
            }
        }
        else
        {
            if(createTable_plat())
            {
                if(selectSQL_plat(id,platpassward))
                {
                    QMessageBox::information(this,"信息提示","登录成功",QMessageBox::Ok);
                    platwindow pw;
                    this->close();
                    pw.exec();
                }
                else
                {
                    QMessageBox::information(this,"信息提示","用户名或密码错误",QMessageBox::Ok);
                }
            }
        }
    }
}

void platform::on_back_plat_clicked()
{
    this->close();
}
