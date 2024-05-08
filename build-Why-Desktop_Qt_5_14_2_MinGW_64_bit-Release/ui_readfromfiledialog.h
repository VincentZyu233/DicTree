/********************************************************************************
** Form generated from reading UI file 'readfromfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READFROMFILEDIALOG_H
#define UI_READFROMFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_readFromFileDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *readFromFileDialog)
    {
        if (readFromFileDialog->objectName().isEmpty())
            readFromFileDialog->setObjectName(QString::fromUtf8("readFromFileDialog"));
        readFromFileDialog->resize(320, 240);
        buttonBox = new QDialogButtonBox(readFromFileDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(readFromFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), readFromFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), readFromFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(readFromFileDialog);
    } // setupUi

    void retranslateUi(QDialog *readFromFileDialog)
    {
        readFromFileDialog->setWindowTitle(QCoreApplication::translate("readFromFileDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readFromFileDialog: public Ui_readFromFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READFROMFILEDIALOG_H
