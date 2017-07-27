#include "inputdialog.h"
#include "ui_inputdialog.h"

inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
}

inputDialog::~inputDialog()
{
    delete ui;
}

void inputDialog::on_addMF_released()
{
    int res;
    inMFsDialog imfdialog;
    imfdialog.setWindowTitle("Add Input MF");
    imfdialog.setModal(true);
    res = imfdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }
}
