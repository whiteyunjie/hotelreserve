#include "managers.h"
#include "ui_managers.h"

managers::managers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managers)
{
    this->setWindowTitle("管理员界面");
    ui->setupUi(this);
    QList<hotelgovern *> gov_List; //记录该酒店的管理员
    for(int i=0;i<hotgov_List.size();i++)
    {
        if(hotgov_List.at(i)->getservience()==hotman_List.at(hotelposition)->getservicelience()) gov_List.append(hotgov_List.at(i));
    }
    ui->managertable->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    ui->managertable->setEditTriggers(QAbstractItemView::NoEditTriggers); //表格禁止编辑
    ui->managertable->verticalHeader()->setVisible(false);  //去掉列表头
    ui->managertable->setColumnCount(2);
    ui->managertable->setRowCount(gov_List.size());
    QStringList header;
    header<<"姓名"<<"密码";
    ui->managertable->setHorizontalHeaderLabels(header); //水平表头
    for(int i=0;i<gov_List.size();i++)
    {
        ui->managertable->setItem(i,0,new QTableWidgetItem(gov_List.at(i)->getname()));
        ui->managertable->setItem(i,1,new QTableWidgetItem(gov_List.at(i)->getpassward()));
    }
    gov_List.clear();
}

managers::~managers()
{
    delete ui;
}

void managers::updatetablegov()
{
    QList<hotelgovern *> gov_List; //记录该酒店的管理员
    for(int i=0;i<hotgov_List.size();i++)
    {
        if(hotgov_List.at(i)->getservience()==hotman_List.at(hotelposition)->getservicelience()) gov_List.append(hotgov_List.at(i));
    }
    ui->managertable->setRowCount(gov_List.size());
    for(int i=0;i<gov_List.size();i++)
    {
        ui->managertable->setItem(i,0,new QTableWidgetItem(gov_List.at(i)->getname()));
        ui->managertable->setItem(i,1,new QTableWidgetItem(gov_List.at(i)->getpassward()));
    }
    gov_List.clear();
}
void managers::on_back_clicked()
{
    this->close();
}

void managers::on_decrease_clicked()
{
    int k=ui->managertable->currentRow();
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中一行",QMessageBox::Ok);
    }
    QList<hotelgovern *> gov_List; //记录该酒店的管理员
    for(int i=0;i<hotgov_List.size();i++)
    {
        if(hotgov_List.at(i)->getservience()==hotman_List.at(hotelposition)->getservicelience()) gov_List.append(hotgov_List.at(i));
    }
    int m=0;
    for(m=0;m<hotgov_List.size();m++)
    {
        if(hotgov_List.at(m)->getname()==gov_List.at(k)->getname())
        {
            hotgov_List.removeOne(hotgov_List.at(m));
            break;
        }
    }
    gov_List.removeOne(gov_List.at(k));
    gov_List.clear();
    updatetablegov();
    update_hotgov();
}

void managers::on_add_clicked()
{
    addman ad;
    connect(&ad,SIGNAL(govtable()),this,SLOT(updatetablegov()));
    ad.exec();
}
