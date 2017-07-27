/********************************************************************************
** Form generated from reading UI file 'outmfsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTMFSDIALOG_H
#define UI_OUTMFSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_outMFsDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *outMFname;
    QDoubleSpinBox *outMFP1;
    QDoubleSpinBox *outMFP2;
    QDoubleSpinBox *outMFP3;
    QDoubleSpinBox *outMFP4;
    QDoubleSpinBox *outMFmax;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *outMFsDialog)
    {
        if (outMFsDialog->objectName().isEmpty())
            outMFsDialog->setObjectName(QStringLiteral("outMFsDialog"));
        outMFsDialog->resize(280, 280);
        layoutWidget = new QWidget(outMFsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 9, 257, 264));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        outMFname = new QLineEdit(layoutWidget);
        outMFname->setObjectName(QStringLiteral("outMFname"));

        verticalLayout_2->addWidget(outMFname);

        outMFP1 = new QDoubleSpinBox(layoutWidget);
        outMFP1->setObjectName(QStringLiteral("outMFP1"));

        verticalLayout_2->addWidget(outMFP1);

        outMFP2 = new QDoubleSpinBox(layoutWidget);
        outMFP2->setObjectName(QStringLiteral("outMFP2"));

        verticalLayout_2->addWidget(outMFP2);

        outMFP3 = new QDoubleSpinBox(layoutWidget);
        outMFP3->setObjectName(QStringLiteral("outMFP3"));

        verticalLayout_2->addWidget(outMFP3);

        outMFP4 = new QDoubleSpinBox(layoutWidget);
        outMFP4->setObjectName(QStringLiteral("outMFP4"));

        verticalLayout_2->addWidget(outMFP4);

        outMFmax = new QDoubleSpinBox(layoutWidget);
        outMFmax->setObjectName(QStringLiteral("outMFmax"));

        verticalLayout_2->addWidget(outMFmax);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox_2 = new QDialogButtonBox(layoutWidget);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox_2);


        retranslateUi(outMFsDialog);

        QMetaObject::connectSlotsByName(outMFsDialog);
    } // setupUi

    void retranslateUi(QDialog *outMFsDialog)
    {
        outMFsDialog->setWindowTitle(QApplication::translate("outMFsDialog", "Dialog", 0));
        label->setText(QApplication::translate("outMFsDialog", "Name", 0));
        label_2->setText(QApplication::translate("outMFsDialog", "P1", 0));
        label_3->setText(QApplication::translate("outMFsDialog", "P2", 0));
        label_4->setText(QApplication::translate("outMFsDialog", "P3", 0));
        label_5->setText(QApplication::translate("outMFsDialog", "P4", 0));
        label_6->setText(QApplication::translate("outMFsDialog", "Maximum", 0));
    } // retranslateUi

};

namespace Ui {
    class outMFsDialog: public Ui_outMFsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTMFSDIALOG_H
