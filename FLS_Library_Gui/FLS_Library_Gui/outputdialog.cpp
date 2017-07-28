//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "outputdialog.h"
#include "ui_outputdialog.h"

outputDialog::outputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Name" << "Type" << "P1" << "P2" << "P3" << "P4" << "Maximum" << "TSK Coefficients";
    ui->outMFtable->setColumnCount(8);
    ui->outMFtable->setHorizontalHeaderLabels(titles);
}

outputDialog::~outputDialog()
{
    delete ui;
}

void outputDialog::on_buttonBox_accepted()
{
    accept();
}

void outputDialog::on_buttonBox_rejected()
{
    reject();
}

void outputDialog::on_addMF_released()
{
    int res;
    QString oMFname;
    QString oMFType;
    double oMFP1;
    double oMFP2;
    double oMFP3;
    double oMFP4;
    double oMFmax;
    QString oTSKC;

    outMFsDialog omfdialog;
    omfdialog.setWindowTitle("Add Output MF");
    omfdialog.setModal(true);
    res = omfdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    oMFname = omfdialog.omfName();
    oMFType = omfdialog.omfType();
    oMFP1 = omfdialog.omfp1();
    oMFP2 = omfdialog.omfp2();
    oMFP3 = omfdialog.omfp3();
    oMFP4 = omfdialog.omfp4();
    oMFmax = omfdialog.omfMax();
    oTSKC = omfdialog.otskc();

    ui->outMFtable->insertRow((ui->outMFtable->rowCount()));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, Name, new QTableWidgetItem(oMFname));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, Type, new QTableWidgetItem(oMFType));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P1, new QTableWidgetItem(QString::number(oMFP1)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P2, new QTableWidgetItem(QString::number(oMFP2)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P3, new QTableWidgetItem(QString::number(oMFP3)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, P4, new QTableWidgetItem(QString::number(oMFP4)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, Maximum, new QTableWidgetItem(QString::number(oMFmax)));
    ui->outMFtable->setItem(ui->outMFtable->rowCount() - 1, TSKC, new QTableWidgetItem(oTSKC));
}

QString outputDialog::outName() const{
    return ui->outname->text();
}
QString outputDialog::outRange() const{
    return ui->outrange->text();
}
int outputDialog::outNumMFs() const{
    return ui->numMFs->value();
}
