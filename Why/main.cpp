#include "mainwindow.h"
#include "my_dictree.h"
#include "initwordlibrarydialog.h"
#include "searchwordlibdialog.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    WordLibraryTree =   createDictionaryTree();
    DicTree =           createDictionaryTree();
    InvalidWordTree =   createDictionaryTree();

    init_Special_words_set();

    MainWindow w;
    w.show();

    initWordLibraryDialog *secDialog = new initWordLibraryDialog();
    secDialog->exec();

    return a.exec();
}
