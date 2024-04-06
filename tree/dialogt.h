#ifndef DIALOGT_H
#define DIALOGT_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include<QTextBrowser>
namespace Ui {
class DialogT;
}

class DialogT : public QDialog
{
    Q_OBJECT

public:
    explicit DialogT(QWidget *parent = nullptr);
    ~DialogT();
    void Myshow();

private:
    void loadFileAndDisplay(QString filePath,QTextBrowser *textBrowser);
    Ui::DialogT *ui;
};

#endif // DIALOGT_H
