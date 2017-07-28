//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "inputdialog.h"
#include "ui_inputdialog.h"


inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Name" << "Type" << "P1" << "P2" << "P3" << "P4" << "Maximum";
    ui->inMFtable->setColumnCount(7);
    ui->inMFtable->setHorizontalHeaderLabels(titles);
}

inputDialog::~inputDialog()
{
    delete ui;
}

void inputDialog::on_addMF_released()
{
    int res;
    QString iMFname;
    QString iMFType;
    double iMFP1;
    double iMFP2;
    double iMFP3;
    double iMFP4;
    double iMFmax;

    inMFsDialog imfdialog;
    imfdialog.setWindowTitle("Add Input MF");
    imfdialog.setModal(true);
    res = imfdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    iMFname = imfdialog.imfName();
    iMFType = imfdialog.imfType();
    iMFP1 = imfdialog.imfp1();
    iMFP2 = imfdialog.imfp2();
    iMFP3 = imfdialog.imfp3();
    iMFP4 = imfdialog.imfp4();
    iMFmax = imfdialog.imfMax();

    ui->inMFtable->insertRow((ui->inMFtable->rowCount()));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, Name, new QTableWidgetItem(iMFname));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, Type, new QTableWidgetItem(iMFType));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P1, new QTableWidgetItem(QString::number(iMFP1)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P2, new QTableWidgetItem(QString::number(iMFP2)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P3, new QTableWidgetItem(QString::number(iMFP3)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, P4, new QTableWidgetItem(QString::number(iMFP4)));
    ui->inMFtable->setItem(ui->inMFtable->rowCount() - 1, Maximum, new QTableWidgetItem(QString::number(iMFmax)));
}

QString inputDialog::inName() const{
    return ui->inname->text();
}
QString inputDialog::inRange() const{
    return ui->inrange->text();
}
int inputDialog::inNumMFs() const{
    return ui->numMFs->value();
}

void inputDialog::on_buttonBox_accepted()
{
    accept();
}

void inputDialog::on_buttonBox_rejected()
{
    reject();
}
