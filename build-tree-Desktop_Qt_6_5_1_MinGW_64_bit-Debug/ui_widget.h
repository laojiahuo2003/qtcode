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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *BtnI;
    QLineEdit *lineEdit;
    QPushButton *okBtn;
    QLabel *label1;
    QPushButton *finishBtn;
    QPushButton *encodeBtn;
    QPushButton *decodeBtn;
    QPushButton *printBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(463, 387);
        BtnI = new QPushButton(Widget);
        BtnI->setObjectName("BtnI");
        BtnI->setGeometry(QRect(190, 210, 81, 31));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 180, 113, 20));
        okBtn = new QPushButton(Widget);
        okBtn->setObjectName("okBtn");
        okBtn->setGeometry(QRect(290, 180, 80, 18));
        label1 = new QLabel(Widget);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(150, 110, 311, 71));
        QFont font;
        font.setPointSize(10);
        label1->setFont(font);
        finishBtn = new QPushButton(Widget);
        finishBtn->setObjectName("finishBtn");
        finishBtn->setGeometry(QRect(290, 210, 80, 18));
        encodeBtn = new QPushButton(Widget);
        encodeBtn->setObjectName("encodeBtn");
        encodeBtn->setGeometry(QRect(190, 240, 81, 31));
        decodeBtn = new QPushButton(Widget);
        decodeBtn->setObjectName("decodeBtn");
        decodeBtn->setGeometry(QRect(190, 270, 81, 31));
        printBtn = new QPushButton(Widget);
        printBtn->setObjectName("printBtn");
        printBtn->setGeometry(QRect(190, 300, 81, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        BtnI->setText(QCoreApplication::translate("Widget", "\345\210\235\345\247\213\345\214\226", nullptr));
        okBtn->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
        label1->setText(QCoreApplication::translate("Widget", "\346\217\220\347\244\272\346\241\206", nullptr));
        finishBtn->setText(QCoreApplication::translate("Widget", "\345\256\214\346\210\220", nullptr));
        encodeBtn->setText(QCoreApplication::translate("Widget", "\347\274\226\347\240\201", nullptr));
        decodeBtn->setText(QCoreApplication::translate("Widget", "\350\257\221\347\240\201", nullptr));
        printBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\215\260\345\223\210\345\244\253\346\233\274\346\240\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
