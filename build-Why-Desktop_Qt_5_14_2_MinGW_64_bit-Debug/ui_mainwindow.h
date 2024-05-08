/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen_file;
    QAction *actionsearch_in_WordLib;
    QAction *actioncheck_userinput_in_WordLib;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *insertNewWord_GroupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QTextEdit *UserInput_textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *AddupWords_Btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *ClearInput_Btn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *searchWord_lineEdit;
    QLabel *label_2;
    QListView *showWord_listView;
    QGroupBox *output_GroupBox;
    QVBoxLayout *verticalLayout_5;
    QPushButton *resetTree_Btn;
    QPushButton *updateOutput_Btn;
    QTextEdit *Output_textEdit;
    QWidget *widget;
    QLabel *Status_label;
    QMenuBar *menubar;
    QMenu *menuovo;
    QMenu *menusearch;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(944, 681);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        actionopen_file = new QAction(MainWindow);
        actionopen_file->setObjectName(QString::fromUtf8("actionopen_file"));
        actionsearch_in_WordLib = new QAction(MainWindow);
        actionsearch_in_WordLib->setObjectName(QString::fromUtf8("actionsearch_in_WordLib"));
        actioncheck_userinput_in_WordLib = new QAction(MainWindow);
        actioncheck_userinput_in_WordLib->setObjectName(QString::fromUtf8("actioncheck_userinput_in_WordLib"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        insertNewWord_GroupBox = new QGroupBox(centralwidget);
        insertNewWord_GroupBox->setObjectName(QString::fromUtf8("insertNewWord_GroupBox"));
        insertNewWord_GroupBox->setMinimumSize(QSize(400, 225));
        insertNewWord_GroupBox->setCursor(QCursor(Qt::ArrowCursor));
        insertNewWord_GroupBox->setTabletTracking(false);
        insertNewWord_GroupBox->setLayoutDirection(Qt::LeftToRight);
        insertNewWord_GroupBox->setAutoFillBackground(false);
        insertNewWord_GroupBox->setFlat(false);
        insertNewWord_GroupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(insertNewWord_GroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        UserInput_textEdit = new QTextEdit(insertNewWord_GroupBox);
        UserInput_textEdit->setObjectName(QString::fromUtf8("UserInput_textEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift Light"));
        UserInput_textEdit->setFont(font);
        UserInput_textEdit->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(UserInput_textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        AddupWords_Btn = new QPushButton(insertNewWord_GroupBox);
        AddupWords_Btn->setObjectName(QString::fromUtf8("AddupWords_Btn"));
        AddupWords_Btn->setMinimumSize(QSize(0, 36));
        AddupWords_Btn->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(AddupWords_Btn);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ClearInput_Btn = new QPushButton(insertNewWord_GroupBox);
        ClearInput_Btn->setObjectName(QString::fromUtf8("ClearInput_Btn"));
        ClearInput_Btn->setMinimumSize(QSize(0, 36));

        horizontalLayout->addWidget(ClearInput_Btn);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_6->addWidget(insertNewWord_GroupBox);

        verticalSpacer = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(400, 225));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        searchWord_lineEdit = new QLineEdit(groupBox);
        searchWord_lineEdit->setObjectName(QString::fromUtf8("searchWord_lineEdit"));
        searchWord_lineEdit->setMinimumSize(QSize(0, 24));

        horizontalLayout_2->addWidget(searchWord_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        showWord_listView = new QListView(groupBox);
        showWord_listView->setObjectName(QString::fromUtf8("showWord_listView"));

        verticalLayout_2->addWidget(showWord_listView);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_6->addWidget(groupBox);


        horizontalLayout_3->addLayout(verticalLayout_6);

        output_GroupBox = new QGroupBox(centralwidget);
        output_GroupBox->setObjectName(QString::fromUtf8("output_GroupBox"));
        verticalLayout_5 = new QVBoxLayout(output_GroupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        resetTree_Btn = new QPushButton(output_GroupBox);
        resetTree_Btn->setObjectName(QString::fromUtf8("resetTree_Btn"));
        resetTree_Btn->setMinimumSize(QSize(0, 36));

        verticalLayout_5->addWidget(resetTree_Btn);

        updateOutput_Btn = new QPushButton(output_GroupBox);
        updateOutput_Btn->setObjectName(QString::fromUtf8("updateOutput_Btn"));
        updateOutput_Btn->setMinimumSize(QSize(0, 36));

        verticalLayout_5->addWidget(updateOutput_Btn);

        Output_textEdit = new QTextEdit(output_GroupBox);
        Output_textEdit->setObjectName(QString::fromUtf8("Output_textEdit"));
        Output_textEdit->setEnabled(true);
        Output_textEdit->setFont(font);
        Output_textEdit->setTabletTracking(false);
        Output_textEdit->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
""));
        Output_textEdit->setReadOnly(true);

        verticalLayout_5->addWidget(Output_textEdit);


        horizontalLayout_3->addWidget(output_GroupBox);


        verticalLayout_7->addLayout(horizontalLayout_3);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_7->addWidget(widget);

        Status_label = new QLabel(centralwidget);
        Status_label->setObjectName(QString::fromUtf8("Status_label"));

        verticalLayout_7->addWidget(Status_label);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 23));
        menuovo = new QMenu(menubar);
        menuovo->setObjectName(QString::fromUtf8("menuovo"));
        menusearch = new QMenu(menubar);
        menusearch->setObjectName(QString::fromUtf8("menusearch"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuovo->menuAction());
        menubar->addAction(menusearch->menuAction());
        menuovo->addAction(actionopen_file);
        menusearch->addAction(actionsearch_in_WordLib);
        menusearch->addAction(actioncheck_userinput_in_WordLib);

        retranslateUi(MainWindow);
        QObject::connect(ClearInput_Btn, SIGNAL(clicked()), UserInput_textEdit, SLOT(clear()));
        QObject::connect(resetTree_Btn, SIGNAL(clicked()), ClearInput_Btn, SLOT(click()));
        QObject::connect(AddupWords_Btn, SIGNAL(clicked()), Status_label, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dictionary Tree QAQ", nullptr));
        actionopen_file->setText(QCoreApplication::translate("MainWindow", "open file...", nullptr));
#if QT_CONFIG(shortcut)
        actionopen_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsearch_in_WordLib->setText(QCoreApplication::translate("MainWindow", "search in WordLib", nullptr));
        actioncheck_userinput_in_WordLib->setText(QCoreApplication::translate("MainWindow", "check userinput in WordLib", nullptr));
        insertNewWord_GroupBox->setTitle(QCoreApplication::translate("MainWindow", "addupNewWord", nullptr));
        AddupWords_Btn->setText(QCoreApplication::translate("MainWindow", "addupWords", nullptr));
        ClearInput_Btn->setText(QCoreApplication::translate("MainWindow", "clearText", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "searchExistedWord", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Search:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "The results will be listed here>>>   (by preffix)", nullptr));
        output_GroupBox->setTitle(QCoreApplication::translate("MainWindow", "outputInfo are here>>>   (by lexical order)", nullptr));
        resetTree_Btn->setText(QCoreApplication::translate("MainWindow", "resetTree", nullptr));
        updateOutput_Btn->setText(QCoreApplication::translate("MainWindow", "\342\206\223update this list\342\206\223", nullptr));
        Output_textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:16px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Words will be listed here, </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">	(First valid then invalid)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; color:#008000;\"><br /></p></body></html>", nullptr));
        Status_label->setText(QCoreApplication::translate("MainWindow", "StatusInfo", nullptr));
        menuovo->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
        menusearch->setTitle(QCoreApplication::translate("MainWindow", "WordLib", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
