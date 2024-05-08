#include "my_dictree.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

PtrToTreeNode WordLibraryTree = NULL;
map<string, string> LibInterpretation;
PtrToTreeNode DicTree = NULL;
PtrToTreeNode InvalidWordTree = NULL;


PtrToTreeNode createDictionaryTree(){
    auto NewNode = new TreeNode;
    NewNode->Data = '!';
    NewNode->Count = NOT_TAIL;
    NewNode->FirstChild = NewNode->NextSibling = NULL;

    return NewNode;
}

PtrToTreeNode insertNode ( PtrToTreeNode parent, PtrToTreeNode NewNode ){
    //新插入节点 是parent所指的结点的儿子
    //插入完成以后 这个函数会返回 指向新插入的节点的指针 / 或者已经存在的节点的指针

    //用ptr去找需要插入的位置
    PtrToTreeNode ptr = parent->FirstChild;

    //case 0: 如果parent没有儿子 直接放置节点
    if ( ptr==NULL ){
        parent->FirstChild = NewNode;
        return NewNode;
    }

    //parent有儿子 下降到parent儿子所在这一层去找
    //cout << "[debug] the first node in this level is " << ptr->Data << '\n';

    //case 1: 新插入的节点的数据的ascii序号比parent的第一个儿子还小， 那头插在最开头
    if ( NewNode->Data < parent->FirstChild->Data  ){
        NewNode->NextSibling = parent->FirstChild;
        parent->FirstChild = NewNode;
        return NewNode;
    }

    //else case 1 : 新插入的节点在这一层已经存在 或
    //新插入的节点需要插入到 除了第一个节点以前的位置
    while ( ptr->NextSibling ){
        //某一层从左到右遍历， 最多到直到最后一个停下来

        if ( ptr->NextSibling == NULL )
            //如果插在最后 或者 新插入的结点与这一层最后一个结点相同 在这里停下里
            break;

        if ( ptr->Data == NewNode->Data )
            //如果已经存在 在这里停下来
            break;

        if ( ptr->NextSibling->Data > NewNode->Data )
            //如果 插入的位置 不是最开头 也不是最结尾 在这里停下来
            break;

        ptr = ptr->NextSibling;
    }

    //case 2: 新插入的节点在这一层已经存在
    if ( ptr->Data == NewNode->Data ){
        //cout << "[debug] Node " << NewNode->Data << " already exists!\n";
        if ( NewNode->Count != NOT_TAIL ){
            //表明 这个结点是某个新插入的单词的最后一个字母
            if ( ptr->Count != NOT_TAIL )
                //而且 这个单词之前已经存在过了
                ptr->Count ++;
            else
                //而且 这个字母是某个已经存在的单词的中间字母，
                //也就是说 新插入的单词是某个已经存在的单词的前缀
                ptr->Count = 1;
        }
        delete( NewNode );
        return ptr;
    }

    //case 3 :  插入在 除了第一个节点之前的 所有位置
    NewNode->NextSibling = ptr->NextSibling;
    ptr->NextSibling = NewNode;
    return NewNode;
}

string toLowerCase( string word ){
    string ret;

    int len = (int) word.length();
    for ( int i=0; i<len; i++ ){
        if ( word[i]>='A' && word[i]<='Z' )
            ret += word[i] += ( 'a'-'A' );
        else
            ret += word[i];
    }

    return ret;
}

void insertWord( PtrToTreeNode DicTree,string word ){
    word = toLowerCase( word );

    PtrToTreeNode LastPosition = DicTree;
    int len = (int)word.length();
    for ( int i=0; i<len; i++ ){
        auto NewNode = new TreeNode;
        //----NewNode info below:----
        NewNode->Data = word[i];
        if ( i==len-1 ){
            NewNode->Count = 1; //表示这个是一个单词的末尾
        } else {
            NewNode->Count = NOT_TAIL;
        }
        NewNode->FirstChild = NewNode->NextSibling = NULL;
        //----NewNode info above:----

        LastPosition = insertNode( LastPosition, NewNode );
    }
}

void DFS_printTree ( PtrToTreeNode RootNode, int NodeLevel ){
    PtrToTreeNode ptr = RootNode;
    int blanks;

    while ( ptr ){
        blanks = 2 * NodeLevel; while(blanks--) cout << ' ';
        cout << ptr->Data << '\n';

        if ( ptr->FirstChild ) DFS_printTree( ptr->FirstChild, NodeLevel+1 );

        ptr = ptr->NextSibling;
    }
}

void debug_PreOrderTraverse(PtrToTreeNode T)    //从博客上拿来的遍历函数
{
    if (T == NULL){
        qDebug() << "[debug] tail!";
        return;
    }

    //cout << T->Data;
    string tmp; tmp += T->Data;
    QString Q_tmp = QString::fromStdString( tmp );
    qDebug() << Q_tmp << ' ';

    debug_PreOrderTraverse(T->FirstChild);
    //cout << T->data << " " ;    //中序遍历
    debug_PreOrderTraverse(T->NextSibling);
    //cout << T->data << " " ;    //后序遍历
}

vector <char> word_buffer;
string outputSingleWord( PtrToTreeNode TailNode ){
    string ThisWordInfo;
    for ( char ch: word_buffer )
        ThisWordInfo+=ch;

//    ThisWordInfo.append(", Count = ");
//    ThisWordInfo.append( to_string (TailNode->Count) );
//    ThisWordInfo.erase( ThisWordInfo.begin() );

    return ThisWordInfo;
}

void DFS_listSingleWord ( PtrToTreeNode T, vector<string> &ret ){
    PtrToTreeNode ptr = T;

    while ( ptr ){
        //cout << ptr->Data;
        word_buffer.push_back( ptr->Data );

        if ( ptr->FirstChild )
            DFS_listSingleWord( ptr->FirstChild, ret  );
        if ( ptr->FirstChild == NULL || ptr->Count!=NOT_TAIL ){
            string wordfound = outputSingleWord(ptr);
            ret.push_back( wordfound );
        }

        //word_buffer.erase(word_buffer.end()-1);
        word_buffer.pop_back();

        ptr = ptr->NextSibling;
    }
}

string outputWordInfo( PtrToTreeNode TailNode ){
    string ThisWordInfo;
    for ( char ch: word_buffer )
        ThisWordInfo+=ch;

    ThisWordInfo.append(", Count = ");
    ThisWordInfo.append( to_string (TailNode->Count) );
    ThisWordInfo.erase( ThisWordInfo.begin() );

    return ThisWordInfo;
}

void DFS_listWordInfo ( PtrToTreeNode T, vector<string> &ret ){
    PtrToTreeNode ptr = T;

    while ( ptr ){
        //cout << ptr->Data;
        word_buffer.push_back( ptr->Data );

        if ( ptr->FirstChild )
            DFS_listWordInfo( ptr->FirstChild, ret  );
        if ( ptr->FirstChild == NULL || ptr->Count!=NOT_TAIL ){
            string wordfound = outputWordInfo(ptr);
            ret.push_back( wordfound );
        }

        //word_buffer.erase(word_buffer.end()-1);
        word_buffer.pop_back();

        ptr = ptr->NextSibling;
    }
}

//void outputWord( PtrToTreeNode TailNode, Ui::MainWindow *ui  ){
//    string thisWordInfo;
//    for ( char ch: word_buffer )
//        thisWordInfo += ch;
//    thisWordInfo.append( ", Count: "); thisWordInfo.append( to_string( TailNode->Count) );
//    //thisWordInfo += '\n';
//    thisWordInfo.erase( thisWordInfo.begin() );
//    QString Q_thisWordInfo = QString::fromStdString(thisWordInfo);

//    ui->Output_textEdit->append(Q_thisWordInfo);
//    //qDebug() << Q_thisWordInfo;
//}
//void DFS_listWord ( PtrToTreeNode T, Ui::MainWindow *ui ){
//    PtrToTreeNode ptr = T;

//    while ( ptr ){
//        //cout << ptr->Data;
//        word_buffer.push_back( ptr->Data );

//        if ( ptr->FirstChild )
//            DFS_listWord ( ptr->FirstChild, ui );
//        if ( ptr->FirstChild == NULL || ptr->Count!=NOT_TAIL )
//            outputWord( ptr, ui );

//        word_buffer.erase(word_buffer.end()-1);

//        ptr = ptr->NextSibling;
//    }

//}



bool isLetterCh( char x ){
    if ( x>='a' && x<='z' ) return true;
    if ( x>='A' && x<='Z' ) return true;

    return false;
}
bool isWordCh( char x ){
    if ( x>='0' && x<='9' ) return true;
    if ( x>='a' && x<='z' ) return true;
    if ( x>='A' && x<='Z' ) return true;
    if ( x=='_' ) return true;
    if ( x=='-' ) return true;
    if ( x=='\'' ) return true;

    return false;
}
bool isSegmentationCh( char x ){
    if ( x==' ' ) return true;
    if ( x=='\n') return true;

    return false;
}

bool isPunctuationCh( char x ){
    if ( x==',' ) return true;
    if ( x=='.' ) return true;
    if ( x=='?' ) return true;
    if ( x=='(' ) return true;
    if ( x==')' ) return true;
    if ( x=='"' ) return true;
    if ( x=='\'') return true;

    return false;
}

set<string> special_words_set;
void init_Special_words_set(){
    special_words_set.insert( "u.s" );
}

//#define INVALID_STR 0
//#define VALID_STR 1
//#define NONSENSE_STR 2
//typedef int typeofstr;
typeofstr isValidWord( string &NewWord ){
    while ( isPunctuationCh( *( NewWord.begin() ) ) )
        NewWord.erase( NewWord.begin() );
    while ( isPunctuationCh( *( NewWord.end()-1 ) ) )
        NewWord.erase( NewWord.end()-1 );

    const int minlen = 2;
    const int maxlen = 20;

    int len = NewWord.length();
    if ( len>=minlen && len<=maxlen ){
        //len in range[2, 20]

        bool isNonsense_flag = true;
        for ( int i=0; i<len; i++ )
            if ( isLetterCh(NewWord[i]) ) isNonsense_flag = false;
        if ( isNonsense_flag )
            return NONSENSE_STR;

        if ( special_words_set.find( NewWord )!=special_words_set.end() ){
            qDebug() << QString::fromStdString( NewWord ) << " , is a special Valid Word";
            return VALID_STR;
        }

        for ( int i=0; i<len; i++ )
            if ( !isWordCh(NewWord[i]) ) return INVALID_STR;

        return VALID_STR;
    }else {
        //len==1 or len>20
        if ( NewWord.compare("a")==0 )
            //长度为1的单词 只有"a"是valid.
            return VALID_STR;
        else
            return NONSENSE_STR;

    }
}

void addupWords ( PtrToTreeNode DicTree, string line ){
    int len = line.length();
    if ( len==0 ){
        qDebug() << "[debug]void addupWords() no useful info";
        return;
    }

    int L=0, R=0;
    while ( L<len ){
        while ( L<len && isSegmentationCh( line[L] ) ) L++;
        if ( L>=len )
            break;

        R = L;

        while ( R<len && !isSegmentationCh( line[R] ) ) R++;
        int NewLen = R - L;
        string NewWord = line.substr( L, NewLen ); //字符串中截取新的单词
        NewWord = toLowerCase( NewWord );          //转换成小写， 现在只统计小写字母
        //cout << "[debug]NewWord: " << NewWord << '\n';

        switch( isValidWord( NewWord ) ){
            case VALID_STR:{
                insertWord( DicTree, NewWord );
                break;
            }
            case INVALID_STR:{
                insertWord( InvalidWordTree, NewWord );
                break;
            }
            case NONSENSE_STR:{
                qDebug() << QString::fromStdString( NewWord ) << " is a non-sense str, ignored";
                break;
            }
        }

        L = R;
    }

}

QString addOneWord_to_LibTree ( string line ){
    int len = line.length();
    if ( len==0 ){
        qDebug() << "[debug]empty line in WordLib.txt";
        return nullptr;
    }

    int i=0;

    while ( i<len && line[i]!='\t' ) i++;
    string NewWord = line.substr( 0, i-0 );

    i++;
    string Comment_of_NewWord = line.substr( i, len-i );

    LibInterpretation[NewWord] = Comment_of_NewWord;

    //NewWord = toLowerCase( NewWord );
    insertWord( WordLibraryTree, NewWord );

    QString ret = QString::fromStdString( NewWord );
    //qDebug() << ret;
    return ret;
}

/*@Override*/
void outputWord( PtrToTreeNode TailNode, string preffix, QStandardItemModel *showWordModel ){
//    cout << preffix;
//    for ( char ch: word_buffer )
//        cout << ch;
//    cout << ", Count: " << TailNode->Count;
//    cout << '\n';

    //preffix.erase( preffix.end()-1 );

    string thisWordInfo;

    thisWordInfo.append( preffix );
    for ( char ch: word_buffer )
        thisWordInfo += ch;
    thisWordInfo.append(", Count: ");
    thisWordInfo.append( to_string( TailNode->Count ) );
//    thisWordInfo += '\n';

    QString Q_thisWordInfo = QString::fromStdString( thisWordInfo );

    showWordModel->appendRow( new QStandardItem(Q_thisWordInfo) );

}

/*@Override*/
void DFS_listWord ( PtrToTreeNode T, string preffix, QStandardItemModel *showWordModel ){
    PtrToTreeNode ptr = T;

    while ( ptr ){
        //cout << ptr->Data;
        word_buffer.push_back( ptr->Data );

        if ( ptr->FirstChild )
            DFS_listWord (ptr->FirstChild, preffix, showWordModel );

        if ( ptr->FirstChild == NULL || ptr->Count!=NOT_TAIL )
            outputWord( ptr, preffix, showWordModel );
        word_buffer.erase(word_buffer.end()-1);\

        ptr = ptr->NextSibling;
    }

}

PtrToTreeNode findWord( PtrToTreeNode RootNode, string word ){
    PtrToTreeNode ptr = RootNode;

    int len = word.length();
    for ( int i=0; i<len; i++ ){
        char x = word[i];
        ptr = ptr->FirstChild;

        while ( ptr ){

            if ( ptr->Data == x )
                break;

            ptr = ptr->NextSibling;
        }

        if ( ptr==NULL )
            //如果这个单词不存在，那么返回空指针
            return NULL;
    }

    //如果这个单词存在，返回最后一个字母的节点的指针
    return ptr;
}

PtrToTreeNode searchPreffix( PtrToTreeNode RootNode, string preffix, QStandardItemModel *showWordModel ){
    int searchMode;
    if ( RootNode==WordLibraryTree ){
        searchMode = WordLibMode;
    } else {
        searchMode = UserInputMode;
    }

    PtrToTreeNode ptr = findWord(RootNode,preffix);

    if ( ptr==NULL ){
        //字母x在字典树中不存在
        //qDebug() << "[debug]" << QString::fromStdString( preffix ) << " not found!";
        QString notExistInfo;
        notExistInfo += '\"' ; notExistInfo.append( QString::fromStdString( preffix ) ); notExistInfo += '\"';
        notExistInfo.append(" not found!");

        showWordModel->appendRow( new QStandardItem( notExistInfo ) );
        //ui->showWord_listView->setModel( showWordModel );
        return NULL;
    }

//    string debug_info;
//    debug_info.append("last letter of preffix: ");
//    debug_info += ptr->Data;
//    qDebug() << "[debug]" << QString::fromStdString( preffix ) << " found! "
//             << "info: " << QString::fromStdString( debug_info );

    if ( ptr->Count != NOT_TAIL ){
        showWordModel->appendRow( new QStandardItem("Word found:\n\t>>>") );

        //the preffix is a word itself
        string thisWordInfo;
        thisWordInfo.append( preffix );
        if ( searchMode == WordLibMode ){
            thisWordInfo.append( ", " + LibInterpretation[preffix] );
        } else {
            thisWordInfo.append( ", Count: ");
            thisWordInfo.append( to_string(ptr->Count) );
        }

        showWordModel->appendRow( new QStandardItem( QString::fromStdString(thisWordInfo) ) );
        showWordModel->appendRow( new QStandardItem("--------------------------------------------------------") );
    }

    if ( ptr->FirstChild != NULL ){
        showWordModel->appendRow( new QStandardItem("You might want to search:\n\t>>>") );
        DFS_listWord( ptr->FirstChild, preffix, showWordModel );
        //ui->showWord_listView->setModel( showWordModel );
    }


    return ptr;
}

void DFS_freeTreeNode( PtrToTreeNode RootNode ){
    PtrToTreeNode ptr = RootNode->FirstChild;

    stack <PtrToTreeNode> st;
    if ( ptr ) st.push( ptr );

    while ( !st.empty() ){
        ptr = st.top(); st.pop();
        //visit;

        if ( ptr->FirstChild )
            st.push( ptr->FirstChild );
        if ( ptr->NextSibling )
            st.push( ptr->NextSibling );

        delete (ptr);
    }

    RootNode->FirstChild = RootNode->NextSibling = NULL;
}
