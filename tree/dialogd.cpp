#include "dialogd.h"
#include "ui_dialogd.h"

DialogD::DialogD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogD)
{
    ui->setupUi(this);
    ui->codefile->setFontPointSize(10);
    //loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\codefile.txt",ui->codefile);

    ui->textfile->setFontPointSize(10);
    //loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\textfile.txt",ui->textfile);

}
void DialogD::Myshow()
{
    loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\codefile.txt",ui->codefile);
    loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\textfile.txt",ui->textfile);

}
void DialogD::loadFileAndDisplay(QString filePath,QTextBrowser *textBrowser)
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

DialogD::~DialogD()
{
    delete ui;
}
