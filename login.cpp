#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录界面");
}

login::~login()
{
    delete ui;
}

void login::on_exit_clicked()
{
    ui->exit->close();
}

void login::on_cuslogbut_clicked()
{
    emit e_cuslog();
}

void login::on_cusregbut_clicked()
{
    emit e_cusreg();
}

void login::on_hotlogbut_clicked()
{
    emit e_hotlog();
}

void login::on_hotregbut_clicked()
{
    emit e_hotreg();
}

void login::on_platlogin_clicked()
{
    emit e_platlog();
}
