#include "dialogt.h"
#include "ui_dialogt.h"

DialogT::DialogT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogT)
{
    ui->setupUi(this);
    ui->treeBrowser->setWordWrapMode(QTextOption::NoWrap);
    ui->treeBrowser->setFontPointSize(6);
    //loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\TreePrint.txt",ui->treeBrowser);

}
void DialogT::Myshow(){
    loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\TreePrint.txt",ui->treeBrowser);

}
void DialogT::loadFileAndDisplay(QString filePath,QTextBrowser *textBrowser)
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

    textBrowser->setPlainText(content);
}

DialogT::~DialogT()
{
    delete ui;
}
