#include "inputspellingcheck.h"
#include "ui_inputspellingcheck.h"

inputSpellingCheck::inputSpellingCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputSpellingCheck)
{
    ui->setupUi(this);
    checkSpelling();
}

inputSpellingCheck::~inputSpellingCheck()
{
    delete ui;
}

void inputSpellingCheck::checkSpelling(){
    vector<string> UserInputValidWords;

    if ( DicTree==NULL ){
        qDebug() << "[ERROR] Nullptr Error!\n";
        return;
    }
    DFS_listSingleWord( DicTree->FirstChild, UserInputValidWords );

    vector<string> correctWords;
    vector<string> strayWords;

    //ui->Output_SpellingCheck_TextEdit->appendPlainText( QString::number( UserInputValidWords.size() ) );
    for ( int i=0; i<(int)UserInputValidWords.size(); i++ ){
        //qDebug() << "QAQWhy";
        string &thisword = UserInputValidWords[i];

        PtrToTreeNode TailNode = findWord( WordLibraryTree, thisword );

        if ( TailNode!=NULL ){
            correctWords.push_back( thisword );
        } else {
            strayWords.push_back( thisword );
        }
    }

    if ( UserInputValidWords.size() == 0 ){
        ui->Output_SpellingCheck_TextEdit->clear();
        ui->Output_SpellingCheck_TextEdit->appendPlainText( "\t[Tip]No Word Found " );
        return;
    }

    //ui->Output_SpellingCheck_TextEdit->appendPlainText("----Correct spelling words: ----\n");
    if ( correctWords.size() == 0 )
        ui->Output_SpellingCheck_TextEdit->appendPlainText("[Tip]No correct word found: \n");
    else
        for ( string str: correctWords ){
            ui->Output_SpellingCheck_TextEdit->appendPlainText( QString::fromStdString(str) +
                                                                "\n  " + QString::fromStdString( LibInterpretation[str] ) );
        }
    //ui->Output_SpellingCheck_TextEdit->appendPlainText("--------------------------------\n");

    //ui->Output_StrayWords_TextEdit->appendPlainText("------Stray spelling words: ----\n");
    if ( strayWords.size() == 0 )
        ui->Output_StrayWords_TextEdit->appendPlainText("[Tip]No stray word found: \n");
    else
        for ( string str: strayWords ){
            ui->Output_StrayWords_TextEdit->appendPlainText( QString::fromStdString(str) );
        }
    //ui->Output_StrayWords_TextEdit->appendPlainText("--------------------------------\n");

}
