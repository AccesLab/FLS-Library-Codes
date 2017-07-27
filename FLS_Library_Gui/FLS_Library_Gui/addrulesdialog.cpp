#include "addrulesdialog.h"
#include "ui_addrulesdialog.h"

addrulesDialog::addrulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrulesDialog)
{
    ui->setupUi(this);
}

addrulesDialog::~addrulesDialog()
{
    delete ui;
}
