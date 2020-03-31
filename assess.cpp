#include "assess.h"
#include "ui_assess.h"

assess::assess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assess)
{
    ui->setupUi(this);
    this->setWindowTitle("评分");
}

assess::~assess()
{
    delete ui;
}

void assess::on_sure_clicked()
{
    if(ui->zero->isChecked()) hot_List.at(hotelposition)->calculate(0.0);
    if(ui->one->isChecked()) hot_List.at(hotelposition)->calculate(1.0);
    if(ui->two->isChecked()) hot_List.at(hotelposition)->calculate(2.0);
    if(ui->three->isChecked()) hot_List.at(hotelposition)->calculate(3.0);
    if(ui->four->isChecked()) hot_List.at(hotelposition)->calculate(4.0);
    if(ui->five->isChecked()) hot_List.at(hotelposition)->calculate(5.0);
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
    this->close();
}
