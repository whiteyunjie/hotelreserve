#ifndef ADDMAN_H
#define ADDMAN_H

#include <QDialog>
#include "manipulate5.h"
#include "hotelmanager.h"
#include "hotels.h"
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelgovern *> hotgov_List;  //存放所有酒店管理员
extern int hotelposition;  //全局变量用来记录当前所登录的酒店的索引
namespace Ui {
class addman;
}

class addman : public QDialog
{
    Q_OBJECT

public:
    explicit addman(QWidget *parent = 0);
    ~addman();

private slots:
    void on_sure_clicked();

    void on_pushButton_clicked();
signals:
    void govtable();
private:
    Ui::addman *ui;
};

#endif // ADDMAN_H
