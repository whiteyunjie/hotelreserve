#include "platwindow.h"
#include "ui_platwindow.h"

platwindow::platwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::platwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("平台界面");
    //酒店信息
    ui->hoteltable->setColumnCount(9);
    ui->hoteltable->setRowCount(hot_List.size());
    ui->hoteltable->verticalHeader()->setVisible(false);
    QStringList header;
    header<<"酒店名"<<"所在城市"<<"酒店地址"<<"营业证号"<<"登录密码"<<"联系电话"<<"审核权限"<<"酒店评分"<<"评分人数";
    ui->hoteltable->setHorizontalHeaderLabels(header);
    ui->hoteltable->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次一行
    ui->hoteltable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    showagain();
    //客户信息
    ui->custable->setColumnCount(5);
    ui->custable->setRowCount(cus_List.size());
    ui->custable->verticalHeader()->setVisible(false);
    QStringList header2;
    header2<<"姓名"<<"性别"<<"身份证号"<<"手机号码"<<"账号密码";
    ui->custable->setHorizontalHeaderLabels(header2);
    ui->hoteltable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i=0;i<cus_List.size();i++)
    {
        ui->custable->setItem(i,0,new QTableWidgetItem(cus_List.at(i)->getname()));
        ui->custable->setItem(i,1,new QTableWidgetItem(cus_List.at(i)->getsex()));
        ui->custable->setItem(i,2,new QTableWidgetItem(cus_List.at(i)->getidentityid()));
        ui->custable->setItem(i,3,new QTableWidgetItem(cus_List.at(i)->getiphonenum()));
        ui->custable->setItem(i,4,new QTableWidgetItem(cus_List.at(i)->getpassward()));
    }
}
platwindow::~platwindow()
{
    delete ui;
}

void platwindow::showagain()  //显示酒店信息
{
    for(int i=0;i<hot_List.size();i++)
    {
        ui->hoteltable->setItem(i,0,new QTableWidgetItem(hot_List.at(i)->gethotelname()));
        ui->hoteltable->setItem(i,1,new QTableWidgetItem(hot_List.at(i)->getcity()));
        ui->hoteltable->setItem(i,2,new QTableWidgetItem(hot_List.at(i)->getaddress()));
        ui->hoteltable->setItem(i,3,new QTableWidgetItem(hotman_List.at(i)->getservicelience()));
        ui->hoteltable->setItem(i,4,new QTableWidgetItem(hotman_List.at(i)->gethotpassward()));
        ui->hoteltable->setItem(i,5,new QTableWidgetItem(hot_List.at(i)->gettelephone()));
        ui->hoteltable->setItem(i,6,new QTableWidgetItem(hotman_List.at(i)->authtransfer()));
        ui->hoteltable->setItem(i,7,new QTableWidgetItem(QString::number(hot_List.at(i)->getjudge())));
        ui->hoteltable->setItem(i,8,new QTableWidgetItem(QString::number(hot_List.at(i)->getpeople())));
    }
}



void platwindow::on_changeau_clicked()
{
    int i;
    bool flag=true;
    int m=ui->hoteltable->currentRow();
    hotman_List.at(m)->changeauthority();
    for(i=0;hotchange[i]>-1;i++)  //遍历到能够写的地方，不能把以前的记录的索引覆盖
    {
        if(hotchange[i]==m)
        {
            flag=false;
            break;
        }
    }
    if(flag) hotchange[i]=m; //记录所更改信息的索引以便写入数据库
    showagain();
}


void platwindow::on_save_clicked()
{
    update_hot();
    QMessageBox::information(this,"信息提示","数据保存成功",QMessageBox::Ok);
}
