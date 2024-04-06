#ifndef MAPVIEWER_H
#define MAPVIEWER_H
#include<QDebug.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
class MapViewer : public QGraphicsView
{
public:
    MapViewer(QWidget *parent = nullptr) : QGraphicsView(parent)
    {
        // 创建场景
        scene = new QGraphicsScene(this);
        setScene(scene);

        // 加载地图图片
        QPixmap mapImage("C:\\Users\\29443\\Desktop\\tu2.png");
        QGraphicsPixmapItem *mapItem = new QGraphicsPixmapItem(mapImage);
        scene->addItem(mapItem);

        // 启用鼠标跟踪
        setMouseTracking(true);
    }

protected:
    void mouseMoveEvent(QMouseEvent *event) override
    {
        // 获取鼠标位置
        QPointF pos = mapToScene(event->pos());

        // 在此处根据鼠标位置进行相应操作，比如显示当前位置的信息等
        // ...
        qDebug()<<pos.rx()<<pos.ry();
        // 调用基类的鼠标移动事件处理
        QGraphicsView::mouseMoveEvent(event);
    }

    void mousePressEvent(QMouseEvent *event) override
    {
        // 在此处处理鼠标点击事件，比如可以选择区域等操作
        // ...

        // 调用基类的鼠标点击事件处理
        QGraphicsView::mousePressEvent(event);
    }

private:
    QGraphicsScene *scene;
};

#endif // MAPVIEWER_H
