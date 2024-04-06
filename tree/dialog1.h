#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    void loadFileAndDisplay(QString filePath);
    ~Dialog1();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
