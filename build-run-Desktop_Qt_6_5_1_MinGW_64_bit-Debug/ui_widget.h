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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cmdLineButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *commitButton;
    QPushButton *cancelButton;
    QPushButton *browseButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 40, 101, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        label->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 110, 51, 31));
        cmdLineButton = new QLineEdit(Widget);
        cmdLineButton->setObjectName("cmdLineButton");
        cmdLineButton->setGeometry(QRect(190, 110, 113, 20));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(160, 210, 254, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        commitButton = new QPushButton(widget);
        commitButton->setObjectName("commitButton");

        horizontalLayout->addWidget(commitButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        browseButton = new QPushButton(widget);
        browseButton->setObjectName("browseButton");

        horizontalLayout->addWidget(browseButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\350\276\223\345\205\245\345\221\275\344\273\244</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\211\223\345\274\200</span></p></body></html>", nullptr));
        commitButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        browseButton->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
