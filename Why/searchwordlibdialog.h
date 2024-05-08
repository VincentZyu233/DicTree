#ifndef SEARCHWORDLIBDIALOG_H
#define SEARCHWORDLIBDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <string>
#include "my_dictree.h"
#include <QDebug>

namespace Ui { //Ui命名空间中 这个窗口的类的前向声明
class searchWordLibDialog;
}

class searchWordLibDialog : public QDialog
{
    Q_OBJECT //Qt信号与槽的宏

public:
    explicit searchWordLibDialog(QWidget *parent = nullptr); //构造函数
    ~searchWordLibDialog(); //析构函数

private slots: //槽函数的声明
    void on_BrowseLib_lineEdit_textChanged(const QString &arg1);

    void on_quit_Btn_clicked();

private: //指向这个ui对象的指针
    Ui::searchWordLibDialog *ui;
};

#endif // SEARCHWORDLIBDIALOG_H
