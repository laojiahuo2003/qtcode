#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    ui->txthfmTree->setFontPointSize(10);
    //loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\hfmTree.txt");
}
// 读取文件内容并显示在 QTextBrowser 中
void Dialog1::loadFileAndDisplay(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file";
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    ui->txthfmTree->setPlainText(content);
}

Dialog1::~Dialog1()
{
    delete ui;
}
