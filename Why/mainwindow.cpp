#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initwordlibrarydialog.h"
#include "searchwordlibdialog.h"
#include "inputspellingcheck.h"
#include "my_dictree.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QString>
#include <QFile>
#include <QFileDialog>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddupWords_Btn_clicked(){
    QString Q_input_str = ui->UserInput_textEdit->toPlainText();
    string input_str = Q_input_str.toStdString();

    if ( input_str.length()==0 ){
        ui->Output_textEdit->append("\n\t[tip]no input detected");
        return;
    }
    addupWords( DicTree, input_str );

    //debug_PreOrderTraverse( DicTree );
    MainWindow::on_updateOutput_Btn_clicked();
}

void MainWindow::on_resetTree_Btn_clicked()
{
    DFS_freeTreeNode( DicTree );
    DFS_freeTreeNode( InvalidWordTree );
    MainWindow::on_updateOutput_Btn_clicked();
}


void MainWindow::on_searchWord_lineEdit_textChanged(const QString &arg1)
{
//    QStandardItemModel *model1 = new QStandardItemModel(this);
//    QStandardItem *item = new QStandardItem("text");
//    model1->appendRow(item);
//    ui->showWord_listView->setModel( model1 );

    QStandardItemModel *hintInfo = new QStandardItemModel();
    hintInfo->appendRow( new QStandardItem("pls enter the word u want to search") );

    QStandardItemModel *showWordModel = new QStandardItemModel();

    if ( ui->searchWord_lineEdit->text().length() > 0 ){
        QString Q_preffix = arg1;
        string preffix = Q_preffix.toStdString();
        searchPreffix( DicTree, preffix, showWordModel );
        ui->showWord_listView->setModel( showWordModel );
    } else{
        ui->showWord_listView->setModel( hintInfo );
        //qDebug() << "shabi";
    }

}


void MainWindow::on_updateOutput_Btn_clicked()
{   
    vector<string> ValidWords, InvalidWords;

    ui->Output_textEdit->clear();
    
    ui->Output_textEdit->append("Counted words: \n");
    if ( DicTree->FirstChild==NULL )
        ui->Output_textEdit->append("  [tip]no word has been added.");
    else{
        DFS_listWordInfo( DicTree,ValidWords );
        //ui->Output_textEdit->append( QString::number( ValidWords.size() ) );
        for ( string ThisWord: ValidWords ){
            ui->Output_textEdit->append( QString::fromStdString( ThisWord ) ); 
        }
    }
        

    ui->Output_textEdit->append("\n----------------------------\n");
    
    ui->Output_textEdit->append("Invalid words: \n");
    if ( InvalidWordTree->FirstChild==NULL )
        ui->Output_textEdit->append("  [tip]no invalid word found.");
    else{
        DFS_listWordInfo( InvalidWordTree, InvalidWords );
        for ( string ThisWord: InvalidWords ){
            ui->Output_textEdit->append( QString::fromStdString( ThisWord ) ); 
        }
    }
        
    ui->Status_label->setText(
                "StatusInfo: " +
                QString::number(ValidWords.size()+InvalidWords.size() ) +
                " words counted" );
}

void MainWindow::on_ClearInput_Btn_clicked()
{

}

void MainWindow::on_actionopen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (fileName.isEmpty())
            return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) )
        return;

    QTextStream in(&file);
    ui->UserInput_textEdit->setText(in.readAll());
    file.close();

    ui->statusbar->showMessage( fileName );

    MainWindow::on_AddupWords_Btn_clicked();
}

void MainWindow::on_actionsearch_in_WordLib_triggered()
{
    searchWordLibDialog *browseLibDialog = new searchWordLibDialog();
    browseLibDialog->exec();
}

void MainWindow::on_actioncheck_userinput_in_WordLib_triggered()
{
    inputSpellingCheck *spellingCheckDialog = new inputSpellingCheck();
    spellingCheckDialog->exec();
}

void MainWindow::on_searchWord_lineEdit_textEdited(const QString &arg1)
{

}
