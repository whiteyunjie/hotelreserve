#include "hoteldetails.h"
#include "ui_hoteldetails.h"

hoteldetails::hoteldetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hoteldetails)
{
    ui->setupUi(this);
    this->setWindowTitle("酒店详情");
    ui->cusroomtable->setColumnCount(5);
    ui->picture->setScaledContents(true);            //通过这样设置可以使图片自己适应大小
    QPixmap *pic=new QPixmap(hot_List.at(hotelposition)->getpohotadd());
    pic->scaled(ui->picture->size(),Qt::KeepAspectRatio);
    ui->picture->setPixmap(*pic);
    ui->welcome->setText(hot_List.at(hotelposition)->gethotelname()+"欢迎您！");
    QStringList header;
    header<<"房间类型"<<"图片"<<"房间余量"<<"日单价"<<"折扣";
    ui->cusroomtable->verticalHeader()->setVisible(false);  //隐藏列表头
    ui->cusroomtable->setHorizontalHeaderLabels(header);
    ui->cusroomtable->setSelectionBehavior(QAbstractItemView::SelectRows);//选中一行
    ui->cusroomtable->horizontalHeader()->setDefaultSectionSize(120);   //设置单元格大小
    ui->cusroomtable->verticalHeader()->setDefaultSectionSize(110);
    QList<guestroom *> roomcur_List; //存放当前酒店所含的客房信息
    for(int i=0;i<room_List.size();i++)
    {
        if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname()) roomcur_List.append(room_List.at(i));
    }
    ui->cusroomtable->setRowCount(roomcur_List.size());
    for(int i=0;i<roomcur_List.size();i++)
    {
        ui->cusroomtable->setItem(i,0,new QTableWidgetItem(roomcur_List.at(i)->gettype()));
        QLabel *label=new QLabel;
        QPixmap *pix=new QPixmap(roomcur_List.at(i)->getroomphototadd());   //插入酒店图片
        pix->scaled(label->size(),Qt::KeepAspectRatio);
        label->setScaledContents(true);
        label->setPixmap(*pix);
        ui->cusroomtable->setCellWidget(i,1,label);
        ui->cusroomtable->setItem(i,2,new QTableWidgetItem(QString::number(roomcur_List.at(i)->getvacanynum())));
        ui->cusroomtable->setItem(i,3,new QTableWidgetItem(QString::number(roomcur_List.at(i)->getprice())));
        ui->cusroomtable->setItem(i,4,new QTableWidgetItem(QString::number(roomcur_List.at(i)->getdiscount())));
    }
    roomcur_List.clear();
}

hoteldetails::~hoteldetails()
{
    delete ui;
}

void hoteldetails::on_order_clicked()
{
    int k=ui->cusroomtable->currentRow();
    if(k==-1)
    {
        QMessageBox::information(this,"信息提示","请选择房间！",QMessageBox::Ok);
    }
    else
    {
        QList<guestroom *> roomcur_List; //存放当前酒店所含的客房信息
        for(int i=0;i<room_List.size();i++)
        {
            if(room_List.at(i)->gethotelname()==hot_List.at(hotelposition)->gethotelname()) roomcur_List.append(room_List.at(i));
        }
        orders *order=new orders(cus_List.at(customerposition)->getname(),cus_List.at(customerposition)->getiphonenum(),roomcur_List.at(k)->gethotelname(),
                                 hot_List.at(hotelposition)->getaddress(),"已付款","申请入住",roomcur_List.at(k)->gettype(),QDate::currentDate(),
                                 0,roomcur_List.at(k)->getprice(),ord_List.size());
        ord_List.append(order);
        trade td;
        td.setdis(roomcur_List.at(k)->getdiscount());
        td.exec();
    }
}

void hoteldetails::on_hotdetailback_clicked()
{
    this->close();
}
