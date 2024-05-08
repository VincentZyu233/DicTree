#ifndef INITWORDLIBRARYDIALOG_H
#define INITWORDLIBRARYDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDir>
#include <QThread>
#include <QDebug>
#include <QListWidget>
#include "my_dictree.h"

namespace Ui {
class initWordLibraryDialog;
}

class LibReader;

class initWordLibraryDialog : public QDialog
{
    Q_OBJECT


public:
    initWordLibraryDialog(QWidget *parent = nullptr);
    ~initWordLibraryDialog();
    void init_readWordLib();

private slots:
    void on_progressUpdated(int progress, QString info );
    void on_error(QString message);
    //void sync_main(int progress, const QString& message);

private:
    Ui::initWordLibraryDialog *ui;
    LibReader* m_libReader;  // 文件读取的LibReader对象
};

#endif // INITWORDLIBRARYDIALOG_H

