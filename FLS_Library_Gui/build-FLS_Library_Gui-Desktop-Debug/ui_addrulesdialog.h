/********************************************************************************
** Form generated from reading UI file 'addrulesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addrulesDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *anticident;
    QLineEdit *consequent;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *andor;

    void setupUi(QDialog *addrulesDialog)
    {
        if (addrulesDialog->objectName().isEmpty())
            addrulesDialog->setObjectName(QStringLiteral("addrulesDialog"));
        addrulesDialog->resize(637, 116);
        buttonBox = new QDialogButtonBox(addrulesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(450, 80, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(addrulesDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 531, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        anticident = new QLineEdit(widget);
        anticident->setObjectName(QStringLiteral("anticident"));

        horizontalLayout_2->addWidget(anticident);

        consequent = new QLineEdit(widget);
        consequent->setObjectName(QStringLiteral("consequent"));

        horizontalLayout_2->addWidget(consequent);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1 = new QWidget(addrulesDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(550, 10, 71, 61));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        andor = new QLineEdit(widget1);
        andor->setObjectName(QStringLiteral("andor"));

        verticalLayout_2->addWidget(andor);


        retranslateUi(addrulesDialog);

        QMetaObject::connectSlotsByName(addrulesDialog);
    } // setupUi

    void retranslateUi(QDialog *addrulesDialog)
    {
        addrulesDialog->setWindowTitle(QApplication::translate("addrulesDialog", "Dialog", 0));
        label->setText(QApplication::translate("addrulesDialog", "Anticident", 0));
        label_2->setText(QApplication::translate("addrulesDialog", "Consequent", 0));
        label_3->setText(QApplication::translate("addrulesDialog", "And/Or", 0));
    } // retranslateUi

};

namespace Ui {
    class addrulesDialog: public Ui_addrulesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRULESDIALOG_H
