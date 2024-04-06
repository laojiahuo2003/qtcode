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
    QPushButton *loginButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLineEdit *password;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(458, 304);
        Widget->setStyleSheet(QString::fromUtf8(""));
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(220, 200, 80, 18));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 120, 40, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 160, 40, 12));
        username = new QLineEdit(Widget);
        username->setObjectName("username");
        username->setGeometry(QRect(210, 110, 113, 20));
        password = new QLineEdit(Widget);
        password->setObjectName("password");
        password->setGeometry(QRect(210, 160, 113, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        loginButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("Widget", "Username", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("Widget", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
