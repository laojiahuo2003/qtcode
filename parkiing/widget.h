#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QProcess>
#include<QString>
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//车辆信息
typedef struct {
    int id;
    int time;//进入时间
    int time2;//从便道进入栈的时间，默认等于time
}carMessage;

//顺序结构栈
typedef struct {
    carMessage *base;
    carMessage* top;
    int stacksize;
}Mystack;
//队列
typedef struct QNode{
    carMessage data;
    struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
//初始化
void InitStack(Mystack& S,int n)
{
    S.stacksize = n;
    S.base = (carMessage*)malloc(sizeof(carMessage) * S.stacksize);
    S.top = S.base;
}

//入栈
int  PushStack(Mystack&S,const carMessage&mes)
{
    if (S.top-S.base>=S.stacksize)
    {
        return 0;
    }
    *S.top++ = mes;
    return 1;
}
//出栈
int  PopStack(Mystack& S, carMessage& mes)
{
    if (S.top == S.base) return 0;
    mes = *--S.top; return 1;
}

//队列初始化
void InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}
//入队
void EnQueue(LinkQueue& Q, const carMessage& mes)
{
    QueuePtr newcar = new QNode;
    newcar->data = mes;
    Q.rear->next = newcar;
    Q.rear = newcar;
}
int QueueLength(LinkQueue& Q)
{
    QNode* p = Q.front;
    int len = 0;
    while (p != Q.rear)
    {
        p = p->next;
        len++;
    }
    return len;
}
//出队
void DeQueue(LinkQueue& Q, carMessage& mes)
{
    if(Q.front!=Q.rear)
    {
        QueuePtr temp = Q.front->next;
        mes = temp->data;
        Q.front->next = temp->next;
        if (Q.rear == temp) Q.rear = Q.front;//如果删除的是尾结点
        delete temp;
    }
}

//背景图
void paintEvent(QPaintEvent * ev);
private slots:

    void on_roomButton_clicked();

    void on_outButton_clicked();

    void on_inButton_clicked();

private:
    Ui::Widget *ui;
    Mystack S1,S2;
    LinkQueue Q;
    QString mes;
    int numin=0;
    int numout=0;
};
#endif // WIDGET_H
