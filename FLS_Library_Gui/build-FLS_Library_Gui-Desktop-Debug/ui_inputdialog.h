/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputDialog
{
public:
    QTableWidget *inMFtable;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *inname;
    QLineEdit *inrange;
    QLineEdit *numMFs;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addMF;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *inputDialog)
    {
        if (inputDialog->objectName().isEmpty())
            inputDialog->setObjectName(QStringLiteral("inputDialog"));
        inputDialog->resize(400, 378);
        inMFtable = new QTableWidget(inputDialog);
        inMFtable->setObjectName(QStringLiteral("inMFtable"));
        inMFtable->setGeometry(QRect(10, 113, 381, 192));
        buttonBox = new QDialogButtonBox(inputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 340, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(inputDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 263, 97));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        inname = new QLineEdit(widget);
        inname->setObjectName(QStringLiteral("inname"));

        verticalLayout->addWidget(inname);

        inrange = new QLineEdit(widget);
        inrange->setObjectName(QStringLiteral("inrange"));

        verticalLayout->addWidget(inrange);

        numMFs = new QLineEdit(widget);
        numMFs->setObjectName(QStringLiteral("numMFs"));

        verticalLayout->addWidget(numMFs);


        horizontalLayout->addLayout(verticalLayout);

        widget1 = new QWidget(inputDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 310, 381, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        addMF = new QPushButton(widget1);
        addMF->setObjectName(QStringLiteral("addMF"));

        horizontalLayout_2->addWidget(addMF);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        retranslateUi(inputDialog);

        QMetaObject::connectSlotsByName(inputDialog);
    } // setupUi

    void retranslateUi(QDialog *inputDialog)
    {
        inputDialog->setWindowTitle(QApplication::translate("inputDialog", "Dialog", 0));
        label->setText(QApplication::translate("inputDialog", "Name", 0));
        label_2->setText(QApplication::translate("inputDialog", "Range", 0));
        label_3->setText(QApplication::translate("inputDialog", "Number of MFs", 0));
        addMF->setText(QApplication::translate("inputDialog", "Add MF", 0));
    } // retranslateUi

};

namespace Ui {
    class inputDialog: public Ui_inputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
