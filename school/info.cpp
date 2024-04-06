#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    setWindowTitle("杭电周游助手-信息查询");
}
void info::setres(const QString& text)
{
    ui->infotext->setText(text); // 设置文本
}
info::~info()
{
    delete ui;
}

//绘制
void info::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("C:\\Users\\29443\\Desktop\\tu1.png"),QRect());

}
