#ifndef MY_DICTREE_H
#define MY_DICTREE_H

#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>

#include <QTextEdit>
#include <QStandardItemModel>
#include <QString>
#include <QDebug>
#include <QStandardItemModel>

using namespace std;

//--------------------------------------------
typedef struct RecTreeNode TreeNode;
typedef TreeNode* PtrToTreeNode; //结构体指针
#define NOT_TAIL -1 //宏，
struct RecTreeNode{ //树结构体声明
    char Data;
    int Count; //不用bool的flag
    //count为-1表示这个不是一个单词的末尾
    //反之如果是一个>=1的数 表示这个是一个单词的计数器

    PtrToTreeNode FirstChild;
    PtrToTreeNode NextSibling;
};// word-> 大小写字母 下划线 撇

extern PtrToTreeNode WordLibraryTree; //十万单词的总字典树
extern map<string, string> LibInterpretation; //总字典树中 每一个单词对应的中文注解
extern PtrToTreeNode DicTree; //根据用户输入建立的树。（记录合法单词
extern PtrToTreeNode InvalidWordTree; //根据用户输入建立的树。（记录不合法单词
extern vector <char> word_buffer; //用于记录遍历结果的单词缓冲区
extern set<string> special_words_set; //用来记录一些特殊拼写的单词， 方便分词， 比如：U.S
//--------------------------------------------

void init_Special_words_set();

PtrToTreeNode createDictionaryTree();

//PtrToTreeNode insertNode ( PtrToTreeNode parent, PtrToTreeNode NewNode ); //插入单个字母

//string toLowerCase( string word );

void insertWord( PtrToTreeNode DicTree,string word ); //插入一个单词

//bool isLetterCh( char x );
//bool isWordCh( char x );
//bool isSegmentationCh( char x );
//bool isPunctuationCh( char x );

#define INVALID_STR 0
#define VALID_STR 1
#define NONSENSE_STR 2
typedef int typeofstr;
//typeofstr isValidWord( string &NewWord );

void addupWords ( PtrToTreeNode DicTree, string line );
QString addOneWord_to_LibTree ( string line ); //专门为十万单词文件编写的函数

void DFS_printTree ( PtrToTreeNode RootNode );
void debug_PreOrderTraverse( PtrToTreeNode T );

//string outputSingleWord( PtrToTreeNode TailNode );
void DFS_listSingleWord ( PtrToTreeNode T, vector<string> &ret );

//string outputWordInfo( PtrToTreeNode TailNode );
void DFS_listWordInfo ( PtrToTreeNode T, vector<string> &ret );

#define WordLibMode 0
#define UserInputMode 1
PtrToTreeNode findWord( PtrToTreeNode RootNode, string word );
PtrToTreeNode searchPreffix( PtrToTreeNode RootNode, string preffix, QStandardItemModel *showWordModel );

void DFS_freeTreeNode( PtrToTreeNode RootNode );

#endif
