#include "orderscus.h"
#include "ui_orderscus.h"

orderscus::orderscus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::orderscus)
{
    ui->setupUi(this);
    this->setWindowTitle("订单信息");
    QString cusiphone=cus_List.at(customerposition)->getiphonenum();
    QList <orders *> ordcusown_List; //该顾客的订单
    for(int i=0;i<ord_List.size();i++)
    {
        if(cusiphone==ord_List.at(i)->getcusiphone()) ordcusown_List.append(ord_List.at(i));
    }
    ui->cusownorders->setColumnCount(6);
    ui->cusownorders->setRowCount(ordcusown_List.size());
    ui->cusownorders->verticalHeader()->setVisible(false);
    ui->cusownorders->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    QStringList header;
    header<<"下单时间"<<"酒店名"<<"房间类型"<<"预订天数"<<"付款金额"<<"订单状态";
    ui->cusownorders->setHorizontalHeaderLabels(header);
    for(int i=0;i<ordcusown_List.size();i++)
    {
        ui->cusownorders->setItem(i,0,new QTableWidgetItem(ordcusown_List.at(i)->getdate().toString()));
        ui->cusownorders->setItem(i,1,new QTableWidgetItem(ordcusown_List.at(i)->gethotelname()));
        ui->cusownorders->setItem(i,2,new QTableWidgetItem(ordcusown_List.at(i)->gettype()));
        ui->cusownorders->setItem(i,3,new QTableWidgetItem(QString::number(ordcusown_List.at(i)->getdays())));
        ui->cusownorders->setItem(i,4,new QTableWidgetItem(QString::number(ordcusown_List.at(i)->getprice())));
        ui->cusownorders->setItem(i,5,new QTableWidgetItem(ordcusown_List.at(i)->getsituation()));
    }
    ordcusown_List.clear();
}

orderscus::~orderscus()
{
    delete ui;
}

void orderscus::updatehotelss()
{

}
void orderscus::updatetable_ord()
{
    QList <orders *> ordcusown_List; //该顾客的订单
    QString cusiphone=cus_List.at(customerposition)->getiphonenum();
    for(int i=0;i<ord_List.size();i++)
    {
        if(cusiphone==ord_List.at(i)->getcusiphone()) ordcusown_List.append(ord_List.at(i));
    }
    ui->cusownorders->setRowCount(ordcusown_List.size());
    for(int i=0;i<ordcusown_List.size();i++)
    {
        ui->cusownorders->setItem(i,0,new QTableWidgetItem(ordcusown_List.at(i)->getdate().toString()));
        ui->cusownorders->setItem(i,1,new QTableWidgetItem(ordcusown_List.at(i)->gethotelname()));
        ui->cusownorders->setItem(i,2,new QTableWidgetItem(ordcusown_List.at(i)->gettype()));
        ui->cusownorders->setItem(i,3,new QTableWidgetItem(QString::number(ordcusown_List.at(i)->getdays())));
        ui->cusownorders->setItem(i,4,new QTableWidgetItem(QString::number(ordcusown_List.at(i)->getprice())));
        ui->cusownorders->setItem(i,5,new QTableWidgetItem(ordcusown_List.at(i)->getsituation()));
    }
    ordcusown_List.clear();
}

void orderscus::on_checkin_clicked()
{
    int k=ui->cusownorders->currentRow();
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中一行",QMessageBox::Ok);
    }
    else
    {
        QList <orders *> ordcusown_List; //该顾客的订单
        QString cusiphone=cus_List.at(customerposition)->getiphonenum();
        for(int i=0;i<ord_List.size();i++)
        {
            if(cusiphone==ord_List.at(i)->getcusiphone()) ordcusown_List.append(ord_List.at(i));
        }
        if(ordcusown_List.at(k)->getsituation()=="已付款")
        {
            QMessageBox::information(this,"信息提示","订单还未被处理，请耐心等待",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="已入住")
        {
            QMessageBox::information(this,"信息提示","您已入住了",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="订单结束")
        {
            QMessageBox::information(this,"信息提示","订单已结束无法操作",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="未入住")
        {

            ordcusown_List.at(k)->changesit("已入住");
            updatetable_ord();
            QMessageBox::information(this,"信息提示","入住成功",QMessageBox::Ok);
        }
    }
}

void orderscus::on_refund_clicked()
{
    int k=ui->cusownorders->currentRow();
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中一行",QMessageBox::Ok);
    }
    else
    {
        QList <orders *> ordcusown_List; //该顾客的订单
        QString cusiphone=cus_List.at(customerposition)->getiphonenum();
        for(int i=0;i<ord_List.size();i++)
        {
            if(cusiphone==ord_List.at(i)->getcusiphone()) ordcusown_List.append(ord_List.at(i));
        }
        if(ordcusown_List.at(k)->getsituation()=="已入住")
        {
            QMessageBox::information(this,"信息提示","您已入住了,无法退款",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="订单结束")
        {
            QMessageBox::information(this,"信息提示","订单已结束无法操作",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="已付款"||ordcusown_List.at(k)->getsituation()=="未入住")
        {
            ordcusown_List.at(k)->changerequest("申请退款");
            QMessageBox::information(this,"信息提示","您的请求会被处理，请等候",QMessageBox::Ok);
        }
    ordcusown_List.clear();
    }
}

void orderscus::on_checkout_clicked()
{
    int k=ui->cusownorders->currentRow();
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中一行",QMessageBox::Ok);
    }
    else
    {
        QList <orders *> ordcusown_List; //该顾客的订单
        QString cusiphone=cus_List.at(customerposition)->getiphonenum();
        for(int i=0;i<ord_List.size();i++)
        {
            if(cusiphone==ord_List.at(i)->getcusiphone()) ordcusown_List.append(ord_List.at(i));
        }
        int i=0;
        for(i=0;i<hot_List.size();i++)             //确定顾客需要评分的是哪个酒店
        {
            if(hot_List.at(i)->gethotelname()==ordcusown_List.at(k)->gethotelname())
            {
                hotelposition=i;
                break;
            }
        }
        if(ordcusown_List.at(k)->getsituation()=="已付款"||ordcusown_List.at(k)->getsituation()=="未入住")
        {
            QMessageBox::information(this,"信息提示","请先申请退款",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="订单结束")
        {
            QMessageBox::information(this,"信息提示","订单已结束无法操作",QMessageBox::Ok);
        }
        if(ordcusown_List.at(k)->getsituation()=="已入住")
        {
            ordcusown_List.at(k)->changerequest("无要求");
            ordcusown_List.at(k)->changesit("订单结束");
            int i=0;
            for(i=0;i<room_List.size();i++)
            {
                if(room_List.at(i)->gethotelname()==ordcusown_List.at(k)->gethotelname()&&room_List.at(i)->gettype()==ordcusown_List.at(k)->gettype()) break;
            }
            room_List.at(i)->checkout();
            assess as;
            as.exec();
            updatetable_ord();
            QMessageBox::information(this,"信息提示","退房成功",QMessageBox::Ok);
        }
    ordcusown_List.clear();
    }
}

void orderscus::on_back_clicked()
{
    emit uphotel();
    this->close();
}
