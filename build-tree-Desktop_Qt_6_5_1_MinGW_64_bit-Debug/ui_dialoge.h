/********************************************************************************
** Form generated from reading UI file 'dialoge.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGE_H
#define UI_DIALOGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogE
{
public:
    QTextBrowser *codefile;
    QTextBrowser *tobetran;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *codeB;

    void setupUi(QDialog *DialogE)
    {
        if (DialogE->objectName().isEmpty())
            DialogE->setObjectName("DialogE");
        DialogE->resize(400, 300);
        codefile = new QTextBrowser(DialogE);
        codefile->setObjectName("codefile");
        codefile->setGeometry(QRect(20, 90, 371, 31));
        tobetran = new QTextBrowser(DialogE);
        tobetran->setObjectName("tobetran");
        tobetran->setGeometry(QRect(20, 30, 371, 31));
        label = new QLabel(DialogE);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 70, 81, 16));
        label_2 = new QLabel(DialogE);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 10, 81, 16));
        codeB = new QTextBrowser(DialogE);
        codeB->setObjectName("codeB");
        codeB->setGeometry(QRect(20, 140, 371, 151));

        retranslateUi(DialogE);

        QMetaObject::connectSlotsByName(DialogE);
    } // setupUi

    void retranslateUi(QDialog *DialogE)
    {
        DialogE->setWindowTitle(QCoreApplication::translate("DialogE", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogE", "codefile.txt", nullptr));
        label_2->setText(QCoreApplication::translate("DialogE", "tobetran.txt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogE: public Ui_DialogE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGE_H
