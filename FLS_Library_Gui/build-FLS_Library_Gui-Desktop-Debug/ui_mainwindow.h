/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_atpic;
    QLabel *label_acpic;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *spinBox_numins;
    QSpinBox *spinBox_numouts;
    QSpinBox *spinBox_numrules;
    QDoubleSpinBox *doubleSpinBox_precisn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(526, 372);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_atpic = new QLabel(centralWidget);
        label_atpic->setObjectName(QStringLiteral("label_atpic"));
        label_atpic->setGeometry(QRect(250, 8, 131, 101));
        label_acpic = new QLabel(centralWidget);
        label_acpic->setObjectName(QStringLiteral("label_acpic"));
        label_acpic->setGeometry(QRect(390, 8, 131, 101));
        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(186, 310, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 6, 134, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(293, 133, 201, 97));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        comboBox = new QComboBox(widget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_6->addWidget(comboBox);

        comboBox_2 = new QComboBox(widget1);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_6->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(widget1);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        verticalLayout_6->addWidget(comboBox_3);


        horizontalLayout_3->addLayout(verticalLayout_6);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 68, 95, 52));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(widget2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(widget2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(10, 272, 299, 29));
        horizontalLayout_2 = new QHBoxLayout(widget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        widget4 = new QWidget(centralWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(11, 132, 249, 130));
        horizontalLayout = new QHBoxLayout(widget4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(widget4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(widget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        spinBox_numins = new QSpinBox(widget4);
        spinBox_numins->setObjectName(QStringLiteral("spinBox_numins"));
        spinBox_numins->setMaximum(9999999);

        verticalLayout_4->addWidget(spinBox_numins);

        spinBox_numouts = new QSpinBox(widget4);
        spinBox_numouts->setObjectName(QStringLiteral("spinBox_numouts"));
        spinBox_numouts->setMaximum(9999999);

        verticalLayout_4->addWidget(spinBox_numouts);

        spinBox_numrules = new QSpinBox(widget4);
        spinBox_numrules->setObjectName(QStringLiteral("spinBox_numrules"));
        spinBox_numrules->setMaximum(9999999);

        verticalLayout_4->addWidget(spinBox_numrules);

        doubleSpinBox_precisn = new QDoubleSpinBox(widget4);
        doubleSpinBox_precisn->setObjectName(QStringLiteral("doubleSpinBox_precisn"));
        doubleSpinBox_precisn->setMaximum(1e+06);

        verticalLayout_4->addWidget(doubleSpinBox_precisn);


        horizontalLayout->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, radioButton_4);
        QWidget::setTabOrder(radioButton_4, radioButton_3);
        QWidget::setTabOrder(radioButton_3, comboBox_2);
        QWidget::setTabOrder(comboBox_2, spinBox_numins);
        QWidget::setTabOrder(spinBox_numins, spinBox_numouts);
        QWidget::setTabOrder(spinBox_numouts, spinBox_numrules);
        QWidget::setTabOrder(spinBox_numrules, doubleSpinBox_precisn);
        QWidget::setTabOrder(doubleSpinBox_precisn, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_atpic->setText(QString());
        label_acpic->setText(QString());
        radioButton->setText(QApplication::translate("MainWindow", "Type-1", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Interval Type-2", 0));
        label_6->setText(QApplication::translate("MainWindow", "And Method", 0));
        label_7->setText(QApplication::translate("MainWindow", "Or Method", 0));
        label->setText(QApplication::translate("MainWindow", "Agg. Method", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "min", 0)
         << QApplication::translate("MainWindow", "prod", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "max", 0)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "max", 0)
         << QApplication::translate("MainWindow", "prod", 0)
        );
        radioButton_4->setText(QApplication::translate("MainWindow", "TSK", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "Mamdani", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add Inputs", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add Outputs", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Add Rules", 0));
        label_2->setText(QApplication::translate("MainWindow", "Number of Inputs", 0));
        label_3->setText(QApplication::translate("MainWindow", "Number of Outputs", 0));
        label_4->setText(QApplication::translate("MainWindow", "Number of Rules", 0));
        label_5->setText(QApplication::translate("MainWindow", "Precision", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
