#ifndef INPUTSPELLINGCHECK_H
#define INPUTSPELLINGCHECK_H

#include <QDialog>
#include <string>
#include "my_dictree.h"
#include <QStandardItemModel>

namespace Ui {
class inputSpellingCheck;
}

class inputSpellingCheck : public QDialog
{
    Q_OBJECT

public:
    void checkSpelling();
    explicit inputSpellingCheck(QWidget *parent = nullptr);
    ~inputSpellingCheck();

private:
    Ui::inputSpellingCheck *ui;
};

#endif // INPUTSPELLINGCHECK_H
