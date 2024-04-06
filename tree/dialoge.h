#ifndef DIALOGE_H
#define DIALOGE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include<QTextBrowser>
namespace Ui {
class DialogE;
}

class DialogE : public QDialog
{
    Q_OBJECT

public:
    explicit DialogE(QWidget *parent = nullptr);
    ~DialogE();
    void addcode(QString ch,QString num);
    void Myshow();

private:
    void loadFileAndDisplay(QString filePath,QTextBrowser *textBrowser);
    Ui::DialogE *ui;
    QString code;
};

#endif // DIALOGE_H
