/********************************************************************************
** Form generated from reading UI file 'inputspellingcheck.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTSPELLINGCHECK_H
#define UI_INPUTSPELLINGCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_inputSpellingCheck
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *Output_SpellingCheck_TextEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *Output_StrayWords_TextEdit;

    void setupUi(QDialog *inputSpellingCheck)
    {
        if (inputSpellingCheck->objectName().isEmpty())
            inputSpellingCheck->setObjectName(QString::fromUtf8("inputSpellingCheck"));
        inputSpellingCheck->resize(600, 450);
        inputSpellingCheck->setMinimumSize(QSize(600, 450));
        horizontalLayout = new QHBoxLayout(inputSpellingCheck);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(inputSpellingCheck);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(400, 0));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Output_SpellingCheck_TextEdit = new QPlainTextEdit(groupBox);
        Output_SpellingCheck_TextEdit->setObjectName(QString::fromUtf8("Output_SpellingCheck_TextEdit"));

        verticalLayout->addWidget(Output_SpellingCheck_TextEdit);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(inputSpellingCheck);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Output_StrayWords_TextEdit = new QPlainTextEdit(groupBox_2);
        Output_StrayWords_TextEdit->setObjectName(QString::fromUtf8("Output_StrayWords_TextEdit"));

        verticalLayout_2->addWidget(Output_StrayWords_TextEdit);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(inputSpellingCheck);

        QMetaObject::connectSlotsByName(inputSpellingCheck);
    } // setupUi

    void retranslateUi(QDialog *inputSpellingCheck)
    {
        inputSpellingCheck->setWindowTitle(QCoreApplication::translate("inputSpellingCheck", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("inputSpellingCheck", "CorrectWords", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("inputSpellingCheck", "StrayWords", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputSpellingCheck: public Ui_inputSpellingCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTSPELLINGCHECK_H
