#include "loginhotel.h"
#include "ui_loginhotel.h"

loginHotel::loginHotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginHotel)
{
    ui->setupUi(this);
}

loginHotel::~loginHotel()
{
    delete ui;
}
