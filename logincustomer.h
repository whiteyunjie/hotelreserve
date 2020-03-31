#ifndef LOGINCUSTOMER_H
#define LOGINCUSTOMER_H

#include <QDialog>

namespace Ui {
class loginCustomer;
}

class loginCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit loginCustomer(QWidget *parent = 0);
    ~loginCustomer();

private:
    Ui::loginCustomer *ui;
};

#endif // LOGINCUSTOMER_H
