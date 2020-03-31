#include "hotelreserve.h"
#include "ui_hotelreserve.h"

hotelreserve::hotelreserve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotelreserve)
{
    ui->setupUi(this);
    this->setWindowTitle("客户预定界面");
    QList<hotels *> hotelavailble_List;  //该List记录的是被平台审核过的酒店的地址
    for(int i=0;i<hot_List.size();i++)
    {
        if(hotman_List.at(i)->getauthority())
        {
            hotelavailble_List.append(hot_List.at(i));
        }
    }
    ui->hotelinfo->setColumnCount(5);
    ui->hotelinfo->setRowCount(hotelavailble_List.size());
    ui->hotelinfo->setSelectionBehavior(QAbstractItemView::SelectRows); //选中一行
    ui->hotelinfo->verticalHeader()->setVisible(false);
    QStringList header;
    header<<"酒店名称"<<"所在城市"<<"地址"<<"最低价格"<<"评分";
    ui->hotelinfo->setHorizontalHeaderLabels(header);
    for(int i=0;i<hotelavailble_List.size();i++)
    {
        ui->hotelinfo->setItem(i,0,new QTableWidgetItem(hotelavailble_List.at(i)->gethotelname()));
        ui->hotelinfo->setItem(i,1,new QTableWidgetItem(hotelavailble_List.at(i)->getcity()));
        ui->hotelinfo->setItem(i,2,new QTableWidgetItem(hotelavailble_List.at(i)->getaddress()));
        ui->hotelinfo->setItem(i,3,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getminiprice())));
        ui->hotelinfo->setItem(i,4,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getjudge())));
    }
    hotelavailble_List.clear();
}

hotelreserve::~hotelreserve()
{
    delete ui;
}

void hotelreserve::on_enquery_clicked()
{
    if(ui->city->text().isEmpty()&&ui->hotelname->text().isEmpty())
    {
        QList<hotels *> hotelavailble_List;  //该List记录的是被平台审核过的酒店的地址
        for(int i=0;i<hot_List.size();i++)
        {
            if(hotman_List.at(i)->getauthority())
            {
                hotelavailble_List.append(hot_List.at(i));
            }
        }
        ui->hotelinfo->setRowCount(hotelavailble_List.size()); //行数需要重新计算
    int k=ui->turnsbase->currentIndex();
    if(k==0) //索引为零是最低价格的排序
    {
        for(int i=0;i<hotelavailble_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
        {
            for(int j=i+1;j<hotelavailble_List.size();j++)
            {
                if(hotelavailble_List.at(j)->getminiprice()<hotelavailble_List.at(i)->getminiprice()) hotelavailble_List.swap(i,j);
            }
        }
    }
    if(k==1) //索引为1是评分的排序
    {
        for(int i=0;i<hotelavailble_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
        {
            for(int j=i+1;j<hotelavailble_List.size();j++)
            {
                if(hotelavailble_List.at(j)->getjudge()<hotelavailble_List.at(i)->getjudge()) hotelavailble_List.swap(i,j);
            }
        }
    }
    int m=ui->turns->currentIndex();  //获得升序或是降序
    if(m==0)  //升序
    {
        for(int i=0;i<hotelavailble_List.size();i++)
        {
            ui->hotelinfo->setItem(i,0,new QTableWidgetItem(hotelavailble_List.at(i)->gethotelname()));
            ui->hotelinfo->setItem(i,1,new QTableWidgetItem(hotelavailble_List.at(i)->getcity()));
            ui->hotelinfo->setItem(i,2,new QTableWidgetItem(hotelavailble_List.at(i)->getaddress()));
            ui->hotelinfo->setItem(i,3,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getminiprice())));
            ui->hotelinfo->setItem(i,4,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getjudge())));
        }
    }
    if(m==1)  //降序
    {
        for(int i=0;i<hotelavailble_List.size();i++)
        {
            ui->hotelinfo->setItem(hotelavailble_List.size()-i-1,0,new QTableWidgetItem(hotelavailble_List.at(i)->gethotelname()));
            ui->hotelinfo->setItem(hotelavailble_List.size()-i-1,1,new QTableWidgetItem(hotelavailble_List.at(i)->getcity()));
            ui->hotelinfo->setItem(hotelavailble_List.size()-i-1,2,new QTableWidgetItem(hotelavailble_List.at(i)->getaddress()));
            ui->hotelinfo->setItem(hotelavailble_List.size()-i-1,3,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getminiprice())));
            ui->hotelinfo->setItem(hotelavailble_List.size()-i-1,4,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getjudge())));
        }
    }
    hotelavailble_List.clear();
    }
    else
    {
        QList<hotels *> hotelavailble_List;  //该List记录的是被平台审核过的酒店的地址
        for(int i=0;i<hot_List.size();i++)
        {
            if(hotman_List.at(i)->getauthority())
            {
                hotelavailble_List.append(hot_List.at(i));
            }
        }
        if(ui->hotelname->text().isEmpty())
        {
            QString city=ui->city->text();
            QList<hotels *> hotelcity_List;  //该List记录城市满足查询要求的酒店
            for(int i=0;i<hotelavailble_List.size();i++)
            {
                if(hotelavailble_List.at(i)->getcity()==city) hotelcity_List.append(hotelavailble_List.at(i));
            }
            ui->hotelinfo->setRowCount(hotelcity_List.size()); //行数需要重新计算
        //然后的排序操作与前面一样
            int k=ui->turnsbase->currentIndex();
            if(k==0) //索引为零是最低价格的排序
            {
                for(int i=0;i<hotelcity_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
                {
                    for(int j=i+1;j<hotelcity_List.size();j++)
                    {
                        if(hotelcity_List.at(j)->getminiprice()<hotelcity_List.at(i)->getminiprice()) hotelcity_List.swap(i,j);
                    }
                }
            }
            if(k==1) //索引为1是评分的排序
            {
                for(int i=0;i<hotelcity_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
                {
                    for(int j=i+1;j<hotelcity_List.size();j++)
                    {
                        if(hotelcity_List.at(j)->getjudge()<hotelcity_List.at(i)->getjudge()) hotelcity_List.swap(i,j);
                    }
                }
            }
            int m=ui->turns->currentIndex();  //获得升序或是降序
            if(m==0)  //升序
            {
                for(int i=0;i<hotelcity_List.size();i++)
                {
                    ui->hotelinfo->setItem(i,0,new QTableWidgetItem(hotelcity_List.at(i)->gethotelname()));
                    ui->hotelinfo->setItem(i,1,new QTableWidgetItem(hotelcity_List.at(i)->getcity()));
                    ui->hotelinfo->setItem(i,2,new QTableWidgetItem(hotelcity_List.at(i)->getaddress()));
                    ui->hotelinfo->setItem(i,3,new QTableWidgetItem(QString::number(hotelcity_List.at(i)->getminiprice())));
                    ui->hotelinfo->setItem(i,4,new QTableWidgetItem(QString::number(hotelcity_List.at(i)->getjudge())));
                }
            }
            if(m==1)  //降序
            {
                for(int i=0;i<hotelcity_List.size();i++)
                {
                    ui->hotelinfo->setItem(hotelcity_List.size()-i-1,0,new QTableWidgetItem(hotelcity_List.at(i)->gethotelname()));
                    ui->hotelinfo->setItem(hotelcity_List.size()-i-1,1,new QTableWidgetItem(hotelcity_List.at(i)->getcity()));
                    ui->hotelinfo->setItem(hotelcity_List.size()-i-1,2,new QTableWidgetItem(hotelcity_List.at(i)->getaddress()));
                    ui->hotelinfo->setItem(hotelcity_List.size()-i-1,3,new QTableWidgetItem(QString::number(hotelcity_List.at(i)->getminiprice())));
                    ui->hotelinfo->setItem(hotelcity_List.size()-i-1,4,new QTableWidgetItem(QString::number(hotelcity_List.at(i)->getjudge())));
                }
            }
        hotelcity_List.clear();
        }
        if(ui->city->text().isEmpty())  //可能有重名酒店
        {
            QString name=ui->hotelname->text();
            QList<hotels *> hotelname_List;  //记录名字满足查询要求的酒店
            for(int i=0;i<hotelavailble_List.size();i++)
            {
                if(hotelavailble_List.at(i)->gethotelname()==name) hotelname_List.append(hotelavailble_List.at(i));
            }
            ui->hotelinfo->setRowCount(hotelname_List.size()); //行数需要重新计算
            int k=ui->turnsbase->currentIndex();
            if(k==0) //索引为零是最低价格的排序
            {
                for(int i=0;i<hotelname_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
                {
                    for(int j=i+1;j<hotelname_List.size();j++)
                    {
                        if(hotelname_List.at(j)->getminiprice()<hotelname_List.at(i)->getminiprice()) hotelname_List.swap(i,j);
                    }
                }
            }
            if(k==1) //索引为1是评分的排序
            {
                for(int i=0;i<hotelname_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
                {
                    for(int j=i+1;j<hotelname_List.size();j++)
                    {
                        if(hotelname_List.at(j)->getjudge()<hotelname_List.at(i)->getjudge()) hotelname_List.swap(i,j);
                    }
                }
            }
            int m=ui->turns->currentIndex();  //获得升序或是降序
            if(m==0)  //升序
            {
                for(int i=0;i<hotelname_List.size();i++)
                {
                    ui->hotelinfo->setItem(i,0,new QTableWidgetItem(hotelname_List.at(i)->gethotelname()));
                    ui->hotelinfo->setItem(i,1,new QTableWidgetItem(hotelname_List.at(i)->getcity()));
                    ui->hotelinfo->setItem(i,2,new QTableWidgetItem(hotelname_List.at(i)->getaddress()));
                    ui->hotelinfo->setItem(i,3,new QTableWidgetItem(QString::number(hotelname_List.at(i)->getminiprice())));
                    ui->hotelinfo->setItem(i,4,new QTableWidgetItem(QString::number(hotelname_List.at(i)->getjudge())));
                }
            }
            if(m==1)  //降序
            {
                for(int i=0;i<hotelname_List.size();i++)
                {
                    ui->hotelinfo->setItem(hotelname_List.size()-i-1,0,new QTableWidgetItem(hotelname_List.at(i)->gethotelname()));
                    ui->hotelinfo->setItem(hotelname_List.size()-i-1,1,new QTableWidgetItem(hotelname_List.at(i)->getcity()));
                    ui->hotelinfo->setItem(hotelname_List.size()-i-1,2,new QTableWidgetItem(hotelname_List.at(i)->getaddress()));
                    ui->hotelinfo->setItem(hotelname_List.size()-i-1,3,new QTableWidgetItem(QString::number(hotelname_List.at(i)->getminiprice())));
                    ui->hotelinfo->setItem(hotelname_List.size()-i-1,4,new QTableWidgetItem(QString::number(hotelname_List.at(i)->getjudge())));
                }
            }
        hotelname_List.clear();
        }
        if(!ui->city->text().isEmpty()&&!ui->hotelname->text().isEmpty())  //酒店名和所在城市的查询都有要求
        {
            QString city=ui->city->text();
            QList<hotels *> hotelcity_List;  //该List记录城市满足查询要求的酒店
            for(int i=0;i<hotelavailble_List.size();i++)
            {
                if(hotelavailble_List.at(i)->getcity()==city) hotelcity_List.append(hotelavailble_List.at(i));
            }
            QString hotelname=ui->hotelname->text();
            QList<hotels *> hotelmuti_List;  //同时满足城市和名字要求的酒店列表
            for(int i=0;i<hotelcity_List.size();i++)
            {
                if(hotelcity_List.at(i)->gethotelname()==hotelname) hotelmuti_List.append(hotelcity_List.at(i));
            }
            ui->hotelinfo->setRowCount(hotelmuti_List.size()); //行数需要重新计算
            int k=ui->turnsbase->currentIndex();
            if(k==0) //索引为零是最低价格的排序
            {
                for(int i=0;i<hotelmuti_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
                {
                    for(int j=i+1;j<hotelmuti_List.size();j++)
                    {
                        if(hotelmuti_List.at(j)->getminiprice()<hotelmuti_List.at(i)->getminiprice()) hotelmuti_List.swap(i,j);
                    }
                }
            }
            if(k==1) //索引为1是评分的排序
            {
                for(int i=0;i<hotelmuti_List.size();i++)             //这里实现的是升序，降序只需要在列表中倒着输出即可
                {
                    for(int j=i+1;j<hotelmuti_List.size();j++)
                    {
                        if(hotelmuti_List.at(j)->getjudge()>hotelmuti_List.at(i)->getjudge()) hotelmuti_List.swap(i,j);
                    }
                }
            }
            int m=ui->turns->currentIndex();  //获得升序或是降序
            if(m==0)  //升序
            {
                for(int i=0;i<hotelmuti_List.size();i++)
                {
                    ui->hotelinfo->setItem(i,0,new QTableWidgetItem(hotelmuti_List.at(i)->gethotelname()));
                    ui->hotelinfo->setItem(i,1,new QTableWidgetItem(hotelmuti_List.at(i)->getcity()));
                    ui->hotelinfo->setItem(i,2,new QTableWidgetItem(hotelmuti_List.at(i)->getaddress()));
                    ui->hotelinfo->setItem(i,3,new QTableWidgetItem(QString::number(hotelmuti_List.at(i)->getminiprice())));
                    ui->hotelinfo->setItem(i,4,new QTableWidgetItem(QString::number(hotelmuti_List.at(i)->getjudge())));
                }
            }
            if(m==1)  //降序
            {
                for(int i=0;i<hotelmuti_List.size();i++)
                {
                    ui->hotelinfo->setItem(hotelmuti_List.size()-i-1,0,new QTableWidgetItem(hotelmuti_List.at(i)->gethotelname()));
                    ui->hotelinfo->setItem(hotelmuti_List.size()-i-1,1,new QTableWidgetItem(hotelmuti_List.at(i)->getcity()));
                    ui->hotelinfo->setItem(hotelmuti_List.size()-i-1,2,new QTableWidgetItem(hotelmuti_List.at(i)->getaddress()));
                    ui->hotelinfo->setItem(hotelmuti_List.size()-i-1,3,new QTableWidgetItem(QString::number(hotelmuti_List.at(i)->getminiprice())));
                    ui->hotelinfo->setItem(hotelmuti_List.size()-i-1,4,new QTableWidgetItem(QString::number(hotelmuti_List.at(i)->getjudge())));
                }
            }
        hotelcity_List.clear();  //处理掉建立的链表
        hotelmuti_List.clear();
        }
    hotelavailble_List.clear();
    }
}

void hotelreserve::on_fordetails_clicked()
{
    int r=ui->hotelinfo->currentRow();  //得到当前所点的行
    QString city=ui->hotelinfo->item(r,1)->text();
    QString add=ui->hotelinfo->item(r,2)->text(); //通过当前所点的城市和地址可以唯一确定酒店
    for(int i=0;i<hot_List.size();i++)
    {
        if(hot_List.at(i)->getcity()==city&&hot_List.at(i)->getaddress()==add) hotelposition=i;
    }
    hoteldetails hd;
    hd.exec();
}

void hotelreserve::on_lookorders_clicked()
{
    orderscus oc;
    connect(&oc,SIGNAL(uphotel()),this,SLOT(uphot()));
    oc.exec();
}

void hotelreserve::on_changeinfo_clicked()
{
    cuschangeinfo cf;
    cf.exec();
}

void hotelreserve::on_pushButton_clicked()
{
     updatesql_cus();//将信息写入数据库
     update_ord();
     update_hot();
     QMessageBox::information(this,"信息提示","数据保存成功",QMessageBox::Ok);
     showtable_ord();
}

void hotelreserve::uphot()
{
    QList<hotels *> hotelavailble_List;  //该List记录的是被平台审核过的酒店的地址
    for(int i=0;i<hot_List.size();i++)
    {
        if(hotman_List.at(i)->getauthority())
        {
            hotelavailble_List.append(hot_List.at(i));
        }
    }
    ui->hotelinfo->setRowCount(hotelavailble_List.size());
    for(int i=0;i<hotelavailble_List.size();i++)
    {
        ui->hotelinfo->setItem(i,0,new QTableWidgetItem(hotelavailble_List.at(i)->gethotelname()));
        ui->hotelinfo->setItem(i,1,new QTableWidgetItem(hotelavailble_List.at(i)->getcity()));
        ui->hotelinfo->setItem(i,2,new QTableWidgetItem(hotelavailble_List.at(i)->getaddress()));
        ui->hotelinfo->setItem(i,3,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getminiprice())));
        ui->hotelinfo->setItem(i,4,new QTableWidgetItem(QString::number(hotelavailble_List.at(i)->getjudge())));
    }
    hotelavailble_List.clear();
}
