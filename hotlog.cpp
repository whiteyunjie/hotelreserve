#include "hotlog.h"
#include "ui_hotlog.h"
#include "manipulate3.h"
#include "manipulate4.h"

hotlog::hotlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotlog)
{
    ui->setupUi(this);
    this->setWindowTitle("酒店登录");
}

hotlog::~hotlog()
{
    delete ui;
}

void hotlog::s_hotlog()
{
    this->exec();
}


void hotlog::on_hotlogin_clicked()
{
    QString servicelience=ui->service_log->text();
    QString hotpassward=ui->passward_log->text();
    int pos; //获得酒店的名字
    if(Connect_hot())
        {
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
        if(!hotgov_List.size())
        {
            read_hotgov();
        }
        showtable_hot();
        showtable_ord();
        close_hot();
        pos=login_hot(servicelience,hotpassward);
        if(pos==-1)
        {
            if(login_hotgov(servicelience,hotpassward))
            {
                QMessageBox::information(this,"信息提示","登录成功",QMessageBox::Ok);
                ui->service_log->clear();
                ui->passward_log->clear();
                isman=true;
                int i=0;
                for(i=0;i<hotman_List.size();i++)
                {
                    if(servicelience==hotman_List.at(i)->getservicelience())
                    {
                        pos=i;
                        break;
                    }
                }
                hotelposition=pos;
                hotelwindow hw;
                this->close();
                hw.exec();
            }
            else
            {
                QMessageBox::information(this,"信息提示","登录失败",QMessageBox::Ok);
                ui->service_log->clear();
                ui->passward_log->clear();
            }
        }
        else
        {
            isman=false;
            QMessageBox::information(this,"信息提示","登录成功",QMessageBox::Ok);
            showtable_hot();
            showtable_room();
            ui->service_log->clear();
            ui->passward_log->clear();
            hotelposition=pos;
            hotelwindow hw;
            this->close();
            hw.exec();
        }
    }
    else qDebug()<<"连接失败";
}

void hotlog::on_hotlogback_clicked()
{
    this->close();
}
