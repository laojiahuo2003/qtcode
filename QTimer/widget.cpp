#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer;
    picID=2;
    //显示图片
    QImage img;
    img.load("C:\\Users\\29443\\Desktop\\qtproject\\objectTimer\\图片\\1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));
    //定时器时间到，发出TIMEOUT信号
    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);

}
void Widget::timeoutSlot()
{
    QString path("C:\\Users\\29443\\Desktop\\qtproject\\objectTimer\\图片\\");
    path+=QString::number(picID);
    path+=".jpg";
    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));
    picID++;
    if(picID==4)
        picID=1;
}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}


void Widget::on_pushButton_2_clicked()
{
    timer->stop();
}


void Widget::on_pushButton_clicked()
{
    QTimer::singleShot(1000,this,SLOT(timeoutSlot()));
}

