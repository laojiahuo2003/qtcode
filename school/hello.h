#ifndef HELLO_H
#define HELLO_H
#include"mypushbutton1.h"
#include <QWidget>
#include<QPainter>
#include<QSignalMapper>
#include<QPropertyAnimation>
const int MAX_VERTEX_NUM = 100;
const int MAX = 100;
const int MAX_LENGTH = 9999999;
typedef struct {
    QString name;
    int id;
    QString info;
}VertexType;
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];                  // 邻接矩阵(权值)
    int vexnum;// 顶点数
    int arcnum;// 弧数
}MGraph;

namespace Ui {
class hello;
}

class hello : public QWidget
{
    Q_OBJECT

public:
    explicit hello(QWidget *parent = nullptr);
    ~hello();
    //背景图
    void paintEvent(QPaintEvent * ev);

public slots:
    void Btn_handle(int index);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::hello *ui;
    QSignalMapper* signalMapper;
    int xy[12][2] = {
        {0, 0}, {30, 25}, {383, 100}, {30, 220}, {210, 250}, {340, 220},
        {428, 225}, {28, 410}, {222, 394}, {256, 576}, {360, 536}, {80, 570}
    };

    MyPushButton1* Btn[12];
    int Point=0;
    MGraph G;
    int num=3;//记录连接的两个点
    int flag=0;//查询模式
    int index0;
    int index1;
    int index2;
    QVector<QLine> lines;   // 用于保存所有绘制的线条(路径）
    QVector<QLine> lines2;   // 用于保存所有绘制的线条（最短路据）

};

#endif // HELLO_H
