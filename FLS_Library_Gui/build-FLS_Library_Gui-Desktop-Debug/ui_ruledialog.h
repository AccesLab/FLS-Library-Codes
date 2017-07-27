/********************************************************************************
** Form generated from reading UI file 'ruledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEDIALOG_H
#define UI_RULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ruleDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ruleDialog)
    {
        if (ruleDialog->objectName().isEmpty())
            ruleDialog->setObjectName(QStringLiteral("ruleDialog"));
        ruleDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ruleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 260, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(ruleDialog);

        QMetaObject::connectSlotsByName(ruleDialog);
    } // setupUi

    void retranslateUi(QDialog *ruleDialog)
    {
        ruleDialog->setWindowTitle(QApplication::translate("ruleDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ruleDialog: public Ui_ruleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEDIALOG_H
