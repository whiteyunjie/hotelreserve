#ifndef MANAGERS_H
#define MANAGERS_H

#include <QDialog>
#include "manipulate5.h"
#include "hotelmanager.h"
#include "hotels.h"
#include "addman.h"
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern QList<hotelgovern *> hotgov_List;  //存放所有酒店管理员
extern int hotelposition;  //全局变量用来记录当前所登录的酒店的索引

namespace Ui {
class managers;
}

class managers : public QDialog
{
    Q_OBJECT

public:
    explicit managers(QWidget *parent = 0);
    ~managers();

private slots:
    void on_back_clicked();

    void on_decrease_clicked();

    void on_add_clicked();

    void updatetablegov();  //更新管理员表格

private:
    Ui::managers *ui;
};

#endif // MANAGERS_H
