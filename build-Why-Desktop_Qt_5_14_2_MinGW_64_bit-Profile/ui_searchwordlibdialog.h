/********************************************************************************
** Form generated from reading UI file 'searchwordlibdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWORDLIBDIALOG_H
#define UI_SEARCHWORDLIBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_searchWordLibDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *searchHint_label;
    QLineEdit *BrowseLib_lineEdit;
    QListView *outputBrowseResult_listView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quit_Btn;

    void setupUi(QDialog *searchWordLibDialog)
    {
        if (searchWordLibDialog->objectName().isEmpty())
            searchWordLibDialog->setObjectName(QString::fromUtf8("searchWordLibDialog"));
        searchWordLibDialog->resize(400, 300);
        searchWordLibDialog->setMinimumSize(QSize(400, 300));
        verticalLayout_2 = new QVBoxLayout(searchWordLibDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchHint_label = new QLabel(searchWordLibDialog);
        searchHint_label->setObjectName(QString::fromUtf8("searchHint_label"));

        horizontalLayout_2->addWidget(searchHint_label);

        BrowseLib_lineEdit = new QLineEdit(searchWordLibDialog);
        BrowseLib_lineEdit->setObjectName(QString::fromUtf8("BrowseLib_lineEdit"));

        horizontalLayout_2->addWidget(BrowseLib_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        outputBrowseResult_listView = new QListView(searchWordLibDialog);
        outputBrowseResult_listView->setObjectName(QString::fromUtf8("outputBrowseResult_listView"));

        verticalLayout_2->addWidget(outputBrowseResult_listView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        quit_Btn = new QPushButton(searchWordLibDialog);
        quit_Btn->setObjectName(QString::fromUtf8("quit_Btn"));

        horizontalLayout->addWidget(quit_Btn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(searchWordLibDialog);

        QMetaObject::connectSlotsByName(searchWordLibDialog);
    } // setupUi

    void retranslateUi(QDialog *searchWordLibDialog)
    {
        searchWordLibDialog->setWindowTitle(QCoreApplication::translate("searchWordLibDialog", "Dialog", nullptr));
        searchHint_label->setText(QCoreApplication::translate("searchWordLibDialog", "Search:", nullptr));
        quit_Btn->setText(QCoreApplication::translate("searchWordLibDialog", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchWordLibDialog: public Ui_searchWordLibDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWORDLIBDIALOG_H
