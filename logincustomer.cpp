#include "logincustomer.h"
#include "ui_logincustomer.h"

loginCustomer::loginCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginCustomer)
{
    ui->setupUi(this);
}

loginCustomer::~loginCustomer()
{
    delete ui;
}
