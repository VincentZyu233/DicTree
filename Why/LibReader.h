#ifndef LIBREADER_H
#define LIBREADER_H

#include <QString>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include "my_dictree.h"

// LibReader类，用于执行文件读取操作
class LibReader : public QObject{
Q_OBJECT

public:
    LibReader(QString filePath, QObject *parent = nullptr);

public slots:
    void readLibFile();

signals:
    void progressUpdated(int progress, QString info);  // 进度更新信号

    void error(QString message);  // 错误信号

private:
    QString m_filePath;  // 文件路径
};

#endif // LIBREADER_H
