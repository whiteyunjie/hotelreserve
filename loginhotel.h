#ifndef LOGINHOTEL_H
#define LOGINHOTEL_H

#include <QDialog>

namespace Ui {
class loginHotel;
}

class loginHotel : public QDialog
{
    Q_OBJECT

public:
    explicit loginHotel(QWidget *parent = 0);
    ~loginHotel();

private:
    Ui::loginHotel *ui;
};

#endif // LOGINHOTEL_H
