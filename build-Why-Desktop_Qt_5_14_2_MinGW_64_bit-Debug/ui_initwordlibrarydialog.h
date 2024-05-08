/********************************************************************************
** Form generated from reading UI file 'initwordlibrarydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITWORDLIBRARYDIALOG_H
#define UI_INITWORDLIBRARYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_initWordLibraryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *ProgressInfo_plainTextEdit;
    QProgressBar *progressBar;

    void setupUi(QDialog *initWordLibraryDialog)
    {
        if (initWordLibraryDialog->objectName().isEmpty())
            initWordLibraryDialog->setObjectName(QString::fromUtf8("initWordLibraryDialog"));
        initWordLibraryDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(initWordLibraryDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ProgressInfo_plainTextEdit = new QPlainTextEdit(initWordLibraryDialog);
        ProgressInfo_plainTextEdit->setObjectName(QString::fromUtf8("ProgressInfo_plainTextEdit"));

        verticalLayout->addWidget(ProgressInfo_plainTextEdit);

        progressBar = new QProgressBar(initWordLibraryDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(initWordLibraryDialog);

        QMetaObject::connectSlotsByName(initWordLibraryDialog);
    } // setupUi

    void retranslateUi(QDialog *initWordLibraryDialog)
    {
        initWordLibraryDialog->setWindowTitle(QCoreApplication::translate("initWordLibraryDialog", "InitWordLib", nullptr));
    } // retranslateUi

};

namespace Ui {
    class initWordLibraryDialog: public Ui_initWordLibraryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITWORDLIBRARYDIALOG_H
