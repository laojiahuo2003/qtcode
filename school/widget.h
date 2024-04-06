#ifndef WIDGET_H
#define WIDGET_H
#include"hello.h"
#include<QMessageBox>
#include <QWidget>
#include<QProcess>
#include<QString>
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //背景图
    void paintEvent(QPaintEvent * ev);

private slots:
    void on_loginButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
