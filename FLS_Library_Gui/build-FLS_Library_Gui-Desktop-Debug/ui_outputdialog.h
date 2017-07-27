/********************************************************************************
** Form generated from reading UI file 'outputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTDIALOG_H
#define UI_OUTPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_outputDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *outputDialog)
    {
        if (outputDialog->objectName().isEmpty())
            outputDialog->setObjectName(QStringLiteral("outputDialog"));
        outputDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(outputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 260, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(outputDialog);

        QMetaObject::connectSlotsByName(outputDialog);
    } // setupUi

    void retranslateUi(QDialog *outputDialog)
    {
        outputDialog->setWindowTitle(QApplication::translate("outputDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class outputDialog: public Ui_outputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTDIALOG_H
