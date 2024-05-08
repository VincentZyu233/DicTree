#include "LibReader.h"

// LibReader类，用于执行文件读取操作
LibReader::LibReader(QString filePath, QObject* parent)
    : QObject(parent), m_filePath(filePath)
{
    // constructor implementation
}

void LibReader::readLibFile() {
        emit progressUpdated(static_cast<int>(0), "[initWordLib]\tbegin:");

        QFile file(m_filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            emit error("WordLib File not found!");  // 发射错误信号
            return;
        }

        int totalLines = 0;
        while (!file.atEnd()) {
            file.readLine();
            totalLines++;
        }

        file.seek(0);
        QTextStream in(&file);
        in.readLine(); //跳过第一行

        int currentLine = 0;
        while (!in.atEnd()) {
            currentLine++;

            QString Q_line = in.readLine();
            std::string line = Q_line.toStdString();

            QString NewWord = addOneWord_to_LibTree(line);  // 添加单词到词库中

            QString initInfoLine;
            initInfoLine.append( "[" + QString::number(currentLine) + "]\t" );
            if (NewWord == nullptr) {
                initInfoLine.append("[tip] empty line");
            } else {
                initInfoLine.append(NewWord);
                initInfoLine.append(" is added into WordLib");
            }

            emit progressUpdated(static_cast<int>(100.0 * currentLine / totalLines), initInfoLine);  // 发射进度信号
        }

        emit progressUpdated(static_cast<int>(100.0), "[initWordLib]\t" +  QString::number(totalLines-1) + " words in total");

        file.close();
}


