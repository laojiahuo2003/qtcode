#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newAction,&QAction::triggered,this,&MainWindow::newActionSlot);
    connect(ui->openAction,&QAction::triggered,this,&MainWindow::openActionSlot);
connect(ui->saveAction,&QAction::triggered,this,&MainWindow::saveActionSlot);
}
void MainWindow::openActionSlot()
{
    QString fileName=QFileDialog::getOpenFileName(this, "选择文件",
    QCoreApplication::applicationFilePath(),
        tr("*.cpp"));
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
        //qDebug()<<fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba=file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}
void MainWindow::newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}
void MainWindow::saveActionSlot()
{
QString reSave_path = QFileDialog::getSaveFileName(this,"选择一个文件",
                          QCoreApplication::applicationFilePath());
if(reSave_path.isEmpty())
   {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
else
{
        QFile file(reSave_path);
       file.open(QIODevice::WriteOnly);
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText().toUtf8());
        file.write(ba);
        file.close();
}
}
MainWindow::~MainWindow()
{
    delete ui;
}

