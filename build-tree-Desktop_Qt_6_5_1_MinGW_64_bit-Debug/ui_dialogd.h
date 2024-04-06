/********************************************************************************
** Form generated from reading UI file 'dialogd.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGD_H
#define UI_DIALOGD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogD
{
public:
    QTextBrowser *codefile;
    QTextBrowser *textfile;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *DialogD)
    {
        if (DialogD->objectName().isEmpty())
            DialogD->setObjectName("DialogD");
        DialogD->resize(400, 300);
        codefile = new QTextBrowser(DialogD);
        codefile->setObjectName("codefile");
        codefile->setGeometry(QRect(60, 40, 291, 61));
        textfile = new QTextBrowser(DialogD);
        textfile->setObjectName("textfile");
        textfile->setGeometry(QRect(60, 140, 291, 61));
        label = new QLabel(DialogD);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 20, 161, 16));
        label_2 = new QLabel(DialogD);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 120, 161, 16));

        retranslateUi(DialogD);

        QMetaObject::connectSlotsByName(DialogD);
    } // setupUi

    void retranslateUi(QDialog *DialogD)
    {
        DialogD->setWindowTitle(QCoreApplication::translate("DialogD", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogD", "codefile.txt", nullptr));
        label_2->setText(QCoreApplication::translate("DialogD", "textfile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogD: public Ui_DialogD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGD_H
