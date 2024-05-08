#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class initWordLibraryDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_AddupWords_Btn_clicked();

    void on_searchWord_lineEdit_textChanged(const QString &arg1);

    void on_resetTree_Btn_clicked();

    void on_updateOutput_Btn_clicked();

    void on_ClearInput_Btn_clicked();

    void on_actionopen_file_triggered();

    void on_actionsearch_in_WordLib_triggered();

    void on_actioncheck_userinput_in_WordLib_triggered();

    void on_searchWord_lineEdit_textEdited(const QString &arg1);
    
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
