#include "hello.h"
#include "ui_hello.h"
#include"info.h"
#include<QDebug>
#include<QTimer>
#include<QThread>
hello::hello(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hello)
{
    ui->setupUi(this);
    setWindowTitle("杭电周游助手");
    //信号分发
    signalMapper = new QSignalMapper(this);
    G.vexnum=11;
    //初始化邻接矩阵的元素
    for (int i = 1; i <= G.vexnum; i++)
    {
        for (int j = 1; j <= G.vexnum; j++)
        {
            G.arcs[i][j] = MAX_LENGTH;
        }
    }

    //设置顶点名称
    G.vexs[1].name="西北田径场";
    G.vexs[2].name="弗雷德广场";
    G.vexs[3].name="击剑馆";
    G.vexs[4].name="图书馆";
    G.vexs[5].name="学生活动中心";
    G.vexs[6].name="东操场";
    G.vexs[7].name="西篮球场";
    G.vexs[8].name="问鼎广场";
    G.vexs[9].name="科技馆";
    G.vexs[10].name="月雅湖";
    G.vexs[11].name="休读院";

    for (int i = 1; i <= G.vexnum; i++) {
        G.vexs[i].id = i;
        QString fileName = QString("C:\\Users\\29443\\Desktop\\%1.png").arg(i);
        Btn[i] = new MyPushButton1(fileName);
        Btn[i]->setParent(this);
        Btn[i]->move(xy[i][0], xy[i][1]); // 坐标
        connect(Btn[i], &QPushButton::clicked, Btn[i], &MyPushButton1::zoom1);
        signalMapper->setMapping(Btn[i], i);
        connect(Btn[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }



    connect(signalMapper, QOverload<int>::of(&QSignalMapper::mappedInt), this, &hello::Btn_handle);
}



hello::~hello()
{
    delete ui;
}


//绘制
void hello::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("C:\\Users\\29443\\Desktop\\tu2.png"),QRect());
    // 设置线条宽度
    QPen pen;
    pen.setWidth(3);  // 设置线条宽度为3个像素
    painter.setPen(pen);
    // 绘制所有保存在lines中的线条
    for (int i = 0; i < lines.size(); i++) {
        painter.drawLine(lines[i]);
    }
    //最短路
    pen.setColor(Qt::red);  // 设置线条颜色为红色
    pen.setWidth(6);
    painter.setPen(pen);

    // 绘制第二组线条
    for (int i = 0; i < lines2.size(); i++) {
        painter.drawLine(lines2[i]);
    }
}



void hello::Btn_handle(int index)
{
    //增加路线逻辑
    if(num<=2){
        if(num==1) index1=index;
        if(num==2) {
            index2=index;
            QPoint p1(xy[index1][0], xy[index1][1]);
            QPoint p2(xy[index2][0], xy[index2][1]);
            int w = qSqrt(QPoint::dotProduct(p1 - p2, p1 - p2));
            qDebug()<<G.vexs[index1].name<<"到"<<G.vexs[index2].name<<"距离为"<<w;
            G.arcs[index1][index2] = w;
            G.arcs[index2][index1] = w;
            G.arcnum+=2;
            //增加路线
            lines.append(QLine(xy[index1][0]+50, xy[index1][1]+45, xy[index2][0]+50, xy[index2][1]+45));
            update();
        }
        num++;
    }
    //选择最短路起点终点逻辑
    if(num>=10)
    {
        if(num==11) index1=index;
        if(num==10){
            index2=index;
            int parent[MAX_VERTEX_NUM];//记录父节点
            bool Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//P[v][w]==true那么w是v0到v最短路径的一个顶点
            int D[MAX_VERTEX_NUM];//长度
            bool final[MAX_VERTEX_NUM];//为True时，证明已经求出最短路径
            // 初始化
            for (int i = 1; i <= G.vexnum; i++) {
                parent[i] = -1;
                if (G.arcs[index1][i] != MAX_LENGTH) parent[i] = index1;
                final[i] = false;
                D[i] = G.arcs[index1][i];
                for (int w = 1; w <= G.vexnum; w++) Path[i][w] = false;
                if (D[i] < MAX_LENGTH) {
                    Path[i][index1] = true;
                    Path[i][i] = true;
                }
            }
            D[index1] = 0;
            final[index1] = true;

            for (int i = 1; i <= G.vexnum; i++)
            {
                int min = MAX_LENGTH + 1;
                int v = 0;

                // 寻找D向量中最小的点和值
                for (int j = 1; j <= G.vexnum; j++)
                {
                    if (!final[j] && D[j] < min) {
                        v = j;
                        min = D[j];
                    }
                }
                final[v] = true;

                // 更新当前最短路径及距离
                for (int j = 1; j <= G.vexnum; j++)
                {
                    if (!final[j] && (min + G.arcs[v][j] < D[j])) {
                        D[j] = min + G.arcs[v][j];
                        parent[j] = v;
                        for (int k = 1; k <= G.vexnum; k++) {
                            Path[j][k] = Path[v][k];
                        }
                        Path[j][j] = true;
                    }
                }
            }
            //添加最终路线
            int tempindex=index2;
            qDebug()<<G.vexs[index2].name;
            while(parent[tempindex]!=-1)
            {
                int preindex=parent[tempindex];
                qDebug()<<"<-----"<<G.vexs[preindex].name;
                lines2.append(QLine(xy[preindex][0]+50, xy[preindex][1]+45, xy[tempindex][0]+50, xy[tempindex][1]+45));
                update();
                tempindex=preindex;
            }
        }
        num--;
    }

    //如果进入查询模式
    if(flag==1)
    {
        QString result;
        result.append("景点代号----->" + QString::number(G.vexs[index].id) + "\n");
        result.append("景点名------->" + G.vexs[index].name + "\n");
        result.append("景点简介----->" + G.vexs[index].info + "\n");
        result.append("附近景点:\n");

        for (int j = 1; j <= G.vexnum; j++) {
        if (G.arcs[index][j] != 0) {
        result.append("景点：" + G.vexs[j].name + "距离" + QString::number(G.arcs[index][j]) + "m" + "\n");
        }
        }
        qDebug()<<result;
        info* newdialog=new info;
        newdialog->setres(result);
        newdialog->show();
        flag=0;
    }
}





void hello::on_pushButton_2_clicked()
{
    flag=0;
    num=1;
}


void hello::on_pushButton_clicked()
{
    flag=0;
    num=11;
    lines2.clear();
}


void hello::on_pushButton_3_clicked()
{
    flag=1;
}

