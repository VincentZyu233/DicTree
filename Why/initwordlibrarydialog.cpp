#include "initwordlibrarydialog.h"
#include "ui_initwordlibrarydialog.h"
#include <QThread>
#include <QFileInfo>
#include <QDir>
#include "LibReader.h"

initWordLibraryDialog::initWordLibraryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::initWordLibraryDialog)
{
    ui->setupUi(this);
    init_readWordLib();
}

initWordLibraryDialog::~initWordLibraryDialog()
{
    delete ui;
}

void initWordLibraryDialog::init_readWordLib(){
    // 获取文件路径
    //QString filePath = QFileInfo(QDir::currentPath() + "/WordLib.txt").absoluteFilePath();
    //QString filePath = "D:/&&&stuffs&&&/Qt/HelloQt/build-Why-Desktop_Qt_5_14_2_MinGW_64_bit-Release/release/WordLib.txt";
    QString filePath = QCoreApplication::applicationDirPath() + "/WordLib.txt";
    qDebug() << QCoreApplication::applicationDirPath();

    // 创建LibReader对象
    m_libReader = new LibReader(filePath);

    // 连接信号和槽
    connect(m_libReader, &LibReader::progressUpdated, this, &initWordLibraryDialog::on_progressUpdated);
    connect(m_libReader, &LibReader::error, this, &initWordLibraryDialog::on_error);

    // 启动文件读取线程
    QThread* readLib_thread = new QThread(this);
    m_libReader->moveToThread(readLib_thread);  // 将LibReader对象移动到新线程
    connect(readLib_thread, &QThread::started, m_libReader, &LibReader::readLibFile);
    readLib_thread->start();
}

void initWordLibraryDialog::on_progressUpdated(int progress, QString info)
{
    ui->progressBar->setValue(progress);  // 更新进度条

    //ui->ProgressInfo_List->addItem(info);
    ui->ProgressInfo_plainTextEdit->appendPlainText(info);
}

void initWordLibraryDialog::on_error(QString message)
{
    //ui->ProgressInfo_List->addItem("[error]\t" + message);  // 显示错误信息
    ui->ProgressInfo_plainTextEdit->appendPlainText(message);
}
