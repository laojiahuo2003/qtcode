/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hello
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *hello)
    {
        if (hello->objectName().isEmpty())
            hello->setObjectName("hello");
        hello->resize(562, 708);
        pushButton = new QPushButton(hello);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(410, 650, 51, 31));
        pushButton_2 = new QPushButton(hello);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(320, 650, 61, 31));
        pushButton_3 = new QPushButton(hello);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(230, 650, 61, 31));

        retranslateUi(hello);

        QMetaObject::connectSlotsByName(hello);
    } // setupUi

    void retranslateUi(QWidget *hello)
    {
        hello->setWindowTitle(QCoreApplication::translate("hello", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("hello", "\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("hello", "\350\277\236\346\216\245", nullptr));
        pushButton_3->setText(QCoreApplication::translate("hello", "\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hello: public Ui_hello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
