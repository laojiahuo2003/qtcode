/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *carId;
    QLineEdit *nowTime;
    QPushButton *inButton;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *room;
    QLabel *label_5;
    QPushButton *roomButton;
    QPushButton *outButton;
    QTextEdit *messageLine;
    QLabel *label_6;
    QLabel *parkspace;
    QLabel *parkspace2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        carId = new QLineEdit(Widget);
        carId->setObjectName("carId");
        carId->setGeometry(QRect(460, 290, 91, 31));
        nowTime = new QLineEdit(Widget);
        nowTime->setObjectName("nowTime");
        nowTime->setGeometry(QRect(460, 330, 91, 31));
        inButton = new QPushButton(Widget);
        inButton->setObjectName("inButton");
        inButton->setGeometry(QRect(460, 370, 41, 31));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 294, 81, 21));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 330, 81, 31));
        room = new QLineEdit(Widget);
        room->setObjectName("room");
        room->setGeometry(QRect(460, 210, 91, 22));
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(390, 210, 51, 21));
        roomButton = new QPushButton(Widget);
        roomButton->setObjectName("roomButton");
        roomButton->setGeometry(QRect(460, 240, 91, 31));
        outButton = new QPushButton(Widget);
        outButton->setObjectName("outButton");
        outButton->setGeometry(QRect(510, 370, 41, 31));
        messageLine = new QTextEdit(Widget);
        messageLine->setObjectName("messageLine");
        messageLine->setGeometry(QRect(30, 70, 301, 431));
        QFont font;
        font.setPointSize(13);
        messageLine->setFont(font);
        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 20, 151, 31));
        QFont font1;
        font1.setPointSize(19);
        font1.setBold(true);
        label_6->setFont(font1);
        parkspace = new QLabel(Widget);
        parkspace->setObjectName("parkspace");
        parkspace->setGeometry(QRect(610, 300, 141, 41));
        parkspace2 = new QLabel(Widget);
        parkspace2->setObjectName("parkspace2");
        parkspace2->setGeometry(QRect(610, 240, 131, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        inButton->setText(QCoreApplication::translate("Widget", "\350\277\233\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\275\246\350\276\206\345\217\267\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\256\271\351\207\217", nullptr));
        roomButton->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
        outButton->setText(QCoreApplication::translate("Widget", "\347\246\273\345\274\200", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\350\277\233\345\207\272\347\212\266\345\206\265\347\273\237\350\256\241", nullptr));
        parkspace->setText(QCoreApplication::translate("Widget", "\345\201\234\350\275\246\345\234\272\345\206\205\350\275\246\350\276\206", nullptr));
        parkspace2->setText(QCoreApplication::translate("Widget", "\344\276\277\351\201\223\345\206\205\350\275\246\350\276\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
