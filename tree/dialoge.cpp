#include "dialoge.h"
#include "ui_dialoge.h"

DialogE::DialogE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogE)
{
    ui->setupUi(this);
    ui->tobetran->setFontPointSize(10);
    //loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\tobetran.txt",ui->tobetran);

    ui->codefile->setFontPointSize(10);
    //loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\codefile.txt",ui->codefile);

}


void DialogE::Myshow(){
    loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\tobetran.txt",ui->tobetran);
    loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\codefile.txt",ui->codefile);
}
void DialogE::loadFileAndDisplay(QString filePath,QTextBrowser *textBrowser)
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
void DialogE::addcode(QString ch,QString num)
{
    ui->codeB->append(ch+"---->"+num);
}

DialogE::~DialogE()
{
    delete ui;
}
