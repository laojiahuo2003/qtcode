#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include<QPainter>
namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();
    void setres(const QString& text);
    //背景图
    void paintEvent(QPaintEvent * ev);
private:
    Ui::info *ui;
};

#endif // INFO_H
