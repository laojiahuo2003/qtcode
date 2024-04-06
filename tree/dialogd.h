#ifndef DIALOGD_H
#define DIALOGD_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include<QTextBrowser>
namespace Ui {
class DialogD;
}

class DialogD : public QDialog
{
    Q_OBJECT

public:
    explicit DialogD(QWidget *parent = nullptr);
    ~DialogD();
    void Myshow();

private:
    void loadFileAndDisplay(QString filePath,QTextBrowser *textBrowser);
    Ui::DialogD *ui;
};

#endif // DIALOGD_H
