#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_exit_clicked();

    void on_cuslogbut_clicked();
    void on_cusregbut_clicked();
    void on_hotlogbut_clicked();
    void on_hotregbut_clicked();
    void on_platlogin_clicked();

signals:
    void e_cuslog();
    void e_cusreg();
    void e_hotlog();
    void e_hotreg();
    void e_platlog();
private:
    Ui::login *ui;
};

#endif // LOGIN_H
