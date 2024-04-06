#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

//绘制背景
void Widget::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap("C:\\Users\\29443\\Desktop\\tu1.png"),QRect());
}

void Widget::on_loginButton_clicked()
{
    this->close();
    if(ui->username->text()=="admin"&&ui->password->text()=="123456"){
        this->close();
        //创建一个新页面
        hello *h=new hello;
        h->show();
    }else{
        QMessageBox::warning(this,tr("登录失败"),tr("用户名或密码输入错误！"),QMessageBox::Ok);
        ui->username->clear();
        ui->password->clear();
        ui->username->setFocus();
    }
}

