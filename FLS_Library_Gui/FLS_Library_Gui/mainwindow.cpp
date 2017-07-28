//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

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
    intableDialog intdialog;
    intdialog.setWindowTitle("Add FLS Input");
    intdialog.setModal(true);
    intdialog.exec();
}

void MainWindow::on_pushButton_3_released()
{
    outtableDialog outtdialog;
    outtdialog.setWindowTitle("Add FLS Output");
    outtdialog.setModal(true);
    outtdialog.exec();
}

void MainWindow::on_pushButton_4_released()
{
    ruleDialog rdialog;
    rdialog.setWindowTitle("Add FLS Rule");
    rdialog.setModal(true);
    rdialog.exec();
}

void MainWindow::on_buttonBox_accepted()
{
    acceptDrops();
    close();
}

void MainWindow::on_buttonBox_rejected()
{
    close();
}
