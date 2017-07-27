#include "outputdialog.h"
#include "ui_outputdialog.h"

outputDialog::outputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputDialog)
{
    ui->setupUi(this);
}

outputDialog::~outputDialog()
{
    delete ui;
}
