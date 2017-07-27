#include "inmfsdialog.h"
#include "ui_inmfsdialog.h"

inMFsDialog::inMFsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inMFsDialog)
{
    ui->setupUi(this);
}

inMFsDialog::~inMFsDialog()
{
    delete ui;
}

void inMFsDialog::on_buttonBox_accepted()
{
    accept();
}

void inMFsDialog::on_buttonBox_rejected()
{
    reject();
}

QString imfName() const{
    return ui->inMFname->text();
}

QString imfType() const{

}

double imfp1() const{

}

double imfp2() const{

}

double imfp3() const{

}

double imfp4() const{

}

double imfMax() const{

}
