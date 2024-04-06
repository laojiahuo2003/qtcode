#ifndef MYPUSHBUTTON1_H
#define MYPUSHBUTTON1_H

#include <QPushButton>

class MyPushButton1 : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton1(QPushButton *parent = nullptr);
    //构造函数参数1正常显示，2按下
    MyPushButton1(QString normalImg,QString pressImg="");
    void zoom1();//向下弹跳
    void zoom2();//向上
    //成员属性
    QString normalImgPath;
    QString pressImgPath;
    int x0,y0;
signals:

};

#endif // MYPUSHBUTTON1_H
