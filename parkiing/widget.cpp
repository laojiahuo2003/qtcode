#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->messageLine->setText("欢迎来到停车场系统,请先设置停车场容量");
    ui->parkspace->setText("停车场内车辆:"+QString::number(numin));
    ui->parkspace2->setText("便道内车辆:"+QString::number(numout));
    ui->label->setStyleSheet("QLabel{color:white;font-size:20px}");
    ui->label_3->setStyleSheet("QLabel{color:white;font-size:20px}");
    ui->label_5->setStyleSheet("QLabel{color:white;font-size:20px}");
    ui->parkspace->setStyleSheet("QLabel{color:white;font-size:20px}");
    ui->parkspace2->setStyleSheet("QLabel{color:white;font-size:20px}");
}

Widget::~Widget()
{
    delete ui;
}

//绘制背景
void Widget::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("C:\\Users\\29443\\Desktop\\qtproject\\parkiing\\background.jpg"),QRect());
}

void Widget::on_roomButton_clicked()
{

    QString room=ui->room->text();
    int n = room.toInt();
    ui->messageLine->append("停车场容量初始化为"+room);
    //显示数量
    ui->parkspace->setText("停车场内车辆:"+QString::number(numin));
    ui->parkspace2->setText("便道内车辆:"+QString::number(numout));

    //初始化
    InitStack(S1,n);
    InitStack(S2,n);
    InitQueue(Q);
}


void Widget::on_outButton_clicked()
{
    //访问编辑行数据
    QString idstring=ui->carId->text();
    QString nowtimestring=ui->nowTime->text();
    //转化为整型
    int id=idstring.toInt();
    int nowtime=nowtimestring.toInt();



    carMessage temp;//输入的删除车辆
    temp.id=id;
    temp.time=nowtime;
    //删除函数被迫展开
     carMessage outCar;
     //在栈中寻找删除的车辆
     //弹出S1元素

     while (PopStack(S1, outCar))
     {
         if (outCar.id == temp.id)
         {
             numin--;
             ui->messageLine->append("车辆号码:"+idstring+" 离开时间:"
             +nowtimestring+"停车时间:"+QString::number(temp.time-outCar.time)+
             "总计收费:"+QString::number(10 * (temp.time - outCar.time2)+5*(outCar.time2-outCar.time)));
             break;
         }
         //压入S2
         PushStack(S2, outCar);
     }
     //S2压回S1
     while (PopStack(S2, outCar))
     {
         PushStack(S1, outCar);
     }
     //在队列寻找删除的车辆（前面的到后面去)
     int length = QueueLength(Q);
     while (length--)
     {
         DeQueue(Q, outCar);
         if (outCar.id == temp.id)
         {
             numout--;
             ui->messageLine->append("车辆号码:"+idstring+" 离开时间:"
             +nowtimestring+"停车时间:"+QString::number(temp.time-outCar.time)+
             "总计收费:"+QString::number(5*(temp.time-outCar.time)));
             break;
         }
         EnQueue(Q, outCar);
     }
     //如果S1未满，队列不为空,则入栈
     while (S1.top-S1.base<S1.stacksize && Q.front != Q.rear)
     {
         numin++;
         numout--;
         DeQueue(Q, outCar);
         outCar.time2 = temp.time;//便道车入栈，修改time2
         PushStack(S1, outCar);
         ui->messageLine->append("车辆号码:"+QString::number(outCar.id) +"从便道进入停车场");
     }

     ui->parkspace->setText("停车场内车辆:"+QString::number(numin));
     ui->parkspace2->setText("便道内车辆:"+QString::number(numout));
}


void Widget::on_inButton_clicked()
{
    //访问编辑行数据
    QString idstring=ui->carId->text();
    QString nowtimestring=ui->nowTime->text();
    int id=idstring.toInt();
    int nowtime=nowtimestring.toInt();
    carMessage temp;
    temp.id=id;
    temp.time=nowtime;
    temp.time2 = temp.time;
    //入栈S1
    if (PushStack(S1, temp))
    {
         numin++;
        ui->messageLine->append("车辆号码:"+idstring+" 进入时间:"+nowtimestring+"进入停车场");
    }
    else{
        //如果栈满则入队
        numout++;
        ui->messageLine->append("车辆号码:"+idstring+" 进入时间:"+nowtimestring+"进入便道");
        EnQueue(Q, temp);
    }
    ui->parkspace->setText("停车场内车辆:"+QString::number(numin));
    ui->parkspace2->setText("便道内车辆:"+QString::number(numout));
}

