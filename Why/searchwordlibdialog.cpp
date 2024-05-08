#include "searchwordlibdialog.h"
#include "ui_searchwordlibdialog.h"

searchWordLibDialog::searchWordLibDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchWordLibDialog)
{
    ui->setupUi(this);
}

searchWordLibDialog::~searchWordLibDialog()
{
    delete ui;
}

void searchWordLibDialog::on_BrowseLib_lineEdit_textChanged(const QString &arg1)
{
    QStandardItemModel *hintInfo = new QStandardItemModel();
    hintInfo->appendRow( new QStandardItem("pls enter the word u want to search") );

    QStandardItemModel *showWordModel = new QStandardItemModel();

    if ( ui->BrowseLib_lineEdit->text().length() > 0 ){
        QString Q_preffix = arg1;
        string preffix = Q_preffix.toStdString();
        searchPreffix( WordLibraryTree, preffix, showWordModel );
        ui->outputBrowseResult_listView->setModel( showWordModel );
    } else{
        ui->outputBrowseResult_listView->setModel( hintInfo );
    }
}

void searchWordLibDialog::on_quit_Btn_clicked()
{
    close();
}
