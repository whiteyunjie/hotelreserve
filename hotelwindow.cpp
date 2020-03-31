#include "hotelwindow.h"
#include "ui_hotelwindow.h"

hotelwindow::hotelwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotelwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("酒店管理界面");
    ui->picture->setScaledContents(true);            //通过这样设置可以使图片自己适应大小
    QPixmap *pic=new QPixmap(hot_List.at(hotelposition)->getpohotadd());
    pic->scaled(ui->picture->size(),Qt::KeepAspectRatio);
    ui->picture->setPixmap(*pic);
    ui->hotelname->setText(hot_List.at(hotelposition)->gethotelname());
    ui->address->setText(hot_List.at(hotelposition)->getaddress());
    ui->telephone->setText(hot_List.at(hotelposition)->gettelephone());
    ui->roomtable->setWindowTitle("房间信息表");
    ui->roomtable->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    ui->roomtable->setEditTriggers(QAbstractItemView::NoEditTriggers); //表格禁止编辑
    QVector<int> roomindex;   //建立一个vector数组记录客房中所有属于该酒店的客房索引
    for(int i=0;i<room_List.size();i++)
    {
        if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
        {
            roomindex.append(i);
        }
    }
    ui->roomtable->setColumnCount(6); //设置列数为6
    ui->roomtable->setRowCount(roomindex.size()); //行数
    QList<orders *> ordhot_List;  //该酒店的订单
    for(int i=0;i<ord_List.size();i++)
    {
        if(ord_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
            ordhot_List.append(ord_List.at(i));
    }
    //行列宽待定
    //设置表头
    QStringList header;
    header<<"房间类型"<<"房间效果图"<<"房间数量"<<"空房数量"<<"日单价"<<"折扣(折)";
    ui->roomtable->setHorizontalHeaderLabels(header); //水平表头
    ui->roomtable->verticalHeader()->setVisible(false);  //去掉列表头
    ui->roomtable->horizontalHeader()->setDefaultSectionSize(120);   //设置单元格大小
    ui->roomtable->verticalHeader()->setDefaultSectionSize(110);
    for(int i=0;i<roomindex.size();i++)
    {
        ui->roomtable->setItem(i,0,new QTableWidgetItem(room_List.at(roomindex[i])->gettype()));
        QLabel *label=new QLabel;
        QPixmap *pix=new QPixmap(room_List.at(i)->getroomphototadd());
        pix->scaled(label->size(),Qt::KeepAspectRatio);
        label->setScaledContents(true);
        label->setPixmap(*pix);
        ui->roomtable->setCellWidget(i,1,label);
        ui->roomtable->setItem(i,2,new QTableWidgetItem(QString("%1").arg(room_List.at(roomindex[i])->getroomnum())));
        ui->roomtable->setItem(i,3,new QTableWidgetItem(QString("%1").arg(room_List.at(roomindex[i])->getvacanynum())));
        ui->roomtable->setItem(i,4,new QTableWidgetItem(QString("%1").arg(room_List.at(roomindex[i])->getprice())));
        ui->roomtable->setItem(i,5,new QTableWidgetItem(QString("%1").arg(room_List.at(roomindex[i])->getdiscount())));

    }
    ui->ordertable->setColumnCount(7);
    ui->ordertable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ordertable->verticalHeader()->setVisible(false);
    ui->ordertable->setRowCount(ordhot_List.size());
    QStringList header2;
    header2<<"客户姓名"<<"客户电话"<<"下单日期"<<"预订房型"<<"预定天数"<<"付款金额"<<"顾客要求";
    ui->ordertable->setHorizontalHeaderLabels(header2);
    for(int i=0;i<ordhot_List.size();i++)
    {
        ui->ordertable->setItem(i,0,new QTableWidgetItem(ordhot_List.at(i)->getcusname()));
        ui->ordertable->setItem(i,1,new QTableWidgetItem(ordhot_List.at(i)->getcusiphone()));
        ui->ordertable->setItem(i,2,new QTableWidgetItem(ordhot_List.at(i)->getdate().toString()));
        ui->ordertable->setItem(i,3,new QTableWidgetItem(ordhot_List.at(i)->gettype()));
        ui->ordertable->setItem(i,4,new QTableWidgetItem(QString::number(ordhot_List.at(i)->getdays())));
        ui->ordertable->setItem(i,5,new QTableWidgetItem(QString::number(ordhot_List.at(i)->getprice())));
        ui->ordertable->setItem(i,6,new QTableWidgetItem(ordhot_List.at(i)->getcusreq()));
    }
    roomindex.clear();
}

hotelwindow::~hotelwindow()
{
    delete ui;
}

void hotelwindow::on_updateinfomation_clicked()
{
    if(!isman)
    {
    hotupdate hu;
    connect(&hu,SIGNAL(uphothot()),this,SLOT(updatetable()));
    connect(&hu,SIGNAL(uphothot()),this,SLOT(updatehotorders()));
    hu.exec();
    }
    else
    {
        QMessageBox::information(this,"信息提示","只有酒店才可以进行此操作",QMessageBox::Ok);
    }
}

void hotelwindow::updatehotorders()
{
    QList<orders *> ordhot_List;  //该酒店的订单
    for(int i=0;i<ord_List.size();i++)
    {
        if(ord_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
            ordhot_List.append(ord_List.at(i));
    }
    for(int i=0;i<ordhot_List.size();i++)
    {
        ui->ordertable->setItem(i,0,new QTableWidgetItem(ordhot_List.at(i)->getcusname()));
        ui->ordertable->setItem(i,1,new QTableWidgetItem(ordhot_List.at(i)->getcusiphone()));
        ui->ordertable->setItem(i,2,new QTableWidgetItem(ordhot_List.at(i)->getdate().toString()));
        ui->ordertable->setItem(i,3,new QTableWidgetItem(ordhot_List.at(i)->gettype()));
        ui->ordertable->setItem(i,4,new QTableWidgetItem(QString::number(ordhot_List.at(i)->getdays())));
        ui->ordertable->setItem(i,5,new QTableWidgetItem(QString::number(ordhot_List.at(i)->getprice())));
        ui->ordertable->setItem(i,6,new QTableWidgetItem(ordhot_List.at(i)->getcusreq()));
    }
    ordhot_List.clear();
}
void hotelwindow::updatetable()
{
    QList<guestroom *> roomhot_List;
    int minprice;  //记录客房中的最低价以便更改酒店中的相应信息
    for(int i=0;i<room_List.size();i++)
    {
        if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
        {
            roomhot_List.append(room_List.at(i));
        }
    }
    if(roomhot_List.size()) minprice=roomhot_List.at(0)->getprice();
    ui->roomtable->setRowCount(roomhot_List.size()); //行数
    ui->hotelname->setText(hot_List.at(hotelposition)->gethotelname());
    ui->address->setText(hot_List.at(hotelposition)->getaddress());
    ui->telephone->setText(hot_List.at(hotelposition)->gettelephone());
    QPixmap *pic=new QPixmap(hot_List.at(hotelposition)->getpohotadd());
    pic->scaled(ui->picture->size(),Qt::KeepAspectRatio);
    ui->picture->setPixmap(*pic);
    for(int i=0;i<roomhot_List.size();i++)
    {
        ui->roomtable->setItem(i,0,new QTableWidgetItem(roomhot_List.at(i)->gettype()));
        QLabel *label=new QLabel;
        QPixmap *pix=new QPixmap(roomhot_List.at(i)->getroomphototadd());
        pix->scaled(label->size(),Qt::KeepAspectRatio);
        label->setScaledContents(true);
        label->setPixmap(*pix);
        ui->roomtable->setCellWidget(i,1,label);
        ui->roomtable->setItem(i,2,new QTableWidgetItem(QString("%1").arg(roomhot_List.at(i)->getroomnum())));
        ui->roomtable->setItem(i,3,new QTableWidgetItem(QString("%1").arg(roomhot_List.at(i)->getvacanynum())));
        ui->roomtable->setItem(i,4,new QTableWidgetItem(QString("%1").arg(roomhot_List.at(i)->getprice())));
        ui->roomtable->setItem(i,5,new QTableWidgetItem(QString("%1").arg(roomhot_List.at(i)->getdiscount())));
        if(roomhot_List.at(i)->getprice()<minprice) minprice=roomhot_List.at(i)->getprice();
    }
    hot_List.at(hotelposition)->setminiprice(minprice);
    roomhot_List.clear();
}
void hotelwindow::on_addroom_clicked()
{
    roominformation rm;
    connect(&rm,SIGNAL(upup()),this,SLOT(updatetable()));
    rm.exec();
    updatetable();
}

void hotelwindow::on_changeroom_clicked()
{
    int k=ui->roomtable->currentRow();
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中一行!",QMessageBox::Ok);
    }
    else{
        roominformation rc;
        rc.getdata(k);
        connect(&rc,SIGNAL(upup()),this,SLOT(updatetable()));
        rc.exec();
    }
}

void hotelwindow::on_deleteroom_clicked()
{
    int m=ui->roomtable->currentRow();  //得到当前行的行数
    QVector<int> roomindex;
    for(int i=0;i<room_List.size();i++)
    {
        if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
        {
            roomindex.append(i);
        }
    }
    room_List.removeOne(room_List.at(roomindex[m]));
    roomindex.clear();
    updatetable();
    update_room();
}

void hotelwindow::on_acceptorder_clicked()
{
    int k=ui->ordertable->currentRow();  //获得当前行的索引
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中订单",QMessageBox::Ok);
    }
    else
    {
        QList<orders *> ordhot_List;  //该酒店的订单
        for(int i=0;i<ord_List.size();i++)
        {
            if(ord_List.at(i)->getaddress()==hot_List.at(hotelposition)->getaddress()&&
                    ord_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
                ordhot_List.append(ord_List.at(i));
        }
        if(ordhot_List.at(k)->getcusreq()=="申请入住")
        {
            ordhot_List.at(k)->changerequest("无要求");
            ordhot_List.at(k)->changesit("未入住");
            QMessageBox::information(this,"信息提示","接单成功",QMessageBox::Ok);
            updatehotorders();
        }
        else
        {
            QMessageBox::information(this,"信息提示","操作无效",QMessageBox::Ok);
        }
        ordhot_List.clear();
    }
}

void hotelwindow::on_agreerefund_clicked()
{
    int k=ui->ordertable->currentRow();  //获得当前行的索引
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选中订单",QMessageBox::Ok);
    }
    else
    {
        QList<orders *> ordhot_List;  //该酒店的订单
        for(int i=0;i<ord_List.size();i++)
        {
            if(ord_List.at(i)->getaddress()==hot_List.at(hotelposition)->getaddress()&&
                    ord_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname())
                ordhot_List.append(ord_List.at(i));
        }
        int i=0;
        for(i=0;i<room_List.size();i++)
        {
            if(ordhot_List.at(k)->gettype()==room_List.at(i)->gettype()&&ordhot_List.at(k)->gethotelname()==room_List.at(i)->gethotelname())
                break;
        }
        if(ordhot_List.at(k)->getcusreq()=="申请退款")
        {

            room_List.at(i)->checkout();
            ordhot_List.at(k)->changerequest("无要求");
            ordhot_List.at(k)->changesit("订单结束");
        QMessageBox::information(this,"信息提示","退款成功",QMessageBox::Ok);
        updatehotorders();
        }
        else
        {
        QMessageBox::information(this,"信息提示","操作无效",QMessageBox::Ok);
        }
    ordhot_List.clear();
    }
}

void hotelwindow::on_savedata_clicked()
{
    bool flag=true;
    int i;
    for(i=0;hotchange[i]>-1;i++)
    {
        if(hotchange[i]==hotelposition)
        {
            flag=false;
            break;
        }
    }
    if(flag) hotchange[i]=hotelposition;
    update_hot();
    update_room();
    update_ord();
    QMessageBox::information(this,"信息提示","数据保存成功",QMessageBox::Ok);
}

void hotelwindow::on_addman_clicked()
{
    if(!isman)
    {
        managers ma;
        ma.exec();
    }
    else
    {
        QMessageBox::information(this,"信息提示","只有酒店才可以进行此操作",QMessageBox::Ok);
    }
}

