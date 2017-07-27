#include "outmfsdialog.h"
#include "ui_outmfsdialog.h"

outMFsDialog::outMFsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outMFsDialog)
{
    ui->setupUi(this);
}

outMFsDialog::~outMFsDialog()
{
    delete ui;
}

void outMFsDialog::on_buttonBox_2_accepted()
{

}
