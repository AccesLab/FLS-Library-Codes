/********************************************************************************
** Form generated from reading UI file 'addrulesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRULESDIALOG_H
#define UI_ADDRULESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_addrulesDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addrulesDialog)
    {
        if (addrulesDialog->objectName().isEmpty())
            addrulesDialog->setObjectName(QStringLiteral("addrulesDialog"));
        addrulesDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addrulesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 270, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(addrulesDialog);

        QMetaObject::connectSlotsByName(addrulesDialog);
    } // setupUi

    void retranslateUi(QDialog *addrulesDialog)
    {
        addrulesDialog->setWindowTitle(QApplication::translate("addrulesDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class addrulesDialog: public Ui_addrulesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRULESDIALOG_H
