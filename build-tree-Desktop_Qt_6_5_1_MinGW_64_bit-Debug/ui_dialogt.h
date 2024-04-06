/********************************************************************************
** Form generated from reading UI file 'dialogt.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGT_H
#define UI_DIALOGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogT
{
public:
    QTextBrowser *treeBrowser;

    void setupUi(QDialog *DialogT)
    {
        if (DialogT->objectName().isEmpty())
            DialogT->setObjectName("DialogT");
        DialogT->resize(400, 300);
        treeBrowser = new QTextBrowser(DialogT);
        treeBrowser->setObjectName("treeBrowser");
        treeBrowser->setGeometry(QRect(10, 10, 381, 271));

        retranslateUi(DialogT);

        QMetaObject::connectSlotsByName(DialogT);
    } // setupUi

    void retranslateUi(QDialog *DialogT)
    {
        DialogT->setWindowTitle(QCoreApplication::translate("DialogT", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogT: public Ui_DialogT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGT_H
