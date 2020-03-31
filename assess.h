#ifndef ASSESS_H
#define ASSESS_H

#include <QDialog>
#include "hotels.h"

extern QList<hotels *> hot_List;  //全局变量作为存放酒店信息的容器
extern int hotelposition;  //全局变量用来记录当前所登录的酒店的索引
extern int hotchange[10];
namespace Ui {
class assess;
}

class assess : public QDialog
{
    Q_OBJECT

public:
    explicit assess(QWidget *parent = 0);
    ~assess();

private slots:
    void on_sure_clicked();

private:
    Ui::assess *ui;
};

#endif // ASSESS_H
