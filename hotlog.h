#ifndef HOTLOG_H
#define HOTLOG_H
#include "hotelwindow.h"
#include <QDialog>
#include "manipulate2.h"
#include "manipulate5.h"
extern int hotelposition;  //全局变量用来记录当前所登录的酒店在容器中的索引
extern QList<hotelgovern *> hotgov_List;  //存放所有酒店管理员
extern QList<hotelmanager *> hotman_List; //存放酒店管理者类的对象
extern bool isman; //判断是酒店还是管理员登录了账号
namespace Ui {
class hotlog;
}

class hotlog : public QDialog
{
    Q_OBJECT

public:
    explicit hotlog(QWidget *parent = 0);
    ~hotlog();

private:
    Ui::hotlog *ui;
private slots:
    void s_hotlog();
    void on_hotlogin_clicked();
    void on_hotlogback_clicked();
};

#endif // HOTLOG_H
