#include "mypushbutton1.h"
#include<qpropertyanimation.h>
//MyPushButton1::MyPushButton1(QWidget *parent)
//    : QWidget{parent}
//{

//}


MyPushButton1::MyPushButton1(QString normalImg,QString pressImg){
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    QPixmap pix;
    bool issuccesss=pix.load(normalImg);
    if(!issuccesss){
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(0.7*QSize(pix.width(),pix.height()));
}

void MyPushButton1::zoom1(){
    //创建动态对象
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+8,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
    QPropertyAnimation*animation1=new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+8,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
void MyPushButton1::zoom2(){
//    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
//    animation->setDuration(200);
//    animation->setStartValue(QRect(this->x(),this->y()+8,this->width(),this->height()));
//    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
//    animation->setEasingCurve(QEasingCurve::OutBounce);
//    animation->start();
}
