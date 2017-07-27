#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("ACCESS FLS Library");

    QPixmap picat("NCA&T_Interlock_Lettermark.png");
    ui->label_atpic->setPixmap(picat);
    QPixmap picacs("accesslab.jpg");
    ui->label_acpic->setPixmap(picacs);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_released()
{
    inputDialog indialog;
    indialog.setWindowTitle("Add FLS Input Port");
    indialog.setModal(true);
    indialog.exec();
}

void MainWindow::on_pushButton_3_released()
{
    outputDialog outdialog;
    outdialog.setWindowTitle("Add FLS Output Port");
    outdialog.setModal(true);
    outdialog.exec();
}

void MainWindow::on_pushButton_4_released()
{
    ruleDialog rdialog;
    rdialog.setWindowTitle("Add FLS Rule");
    rdialog.setModal(true);
    rdialog.exec();
}
