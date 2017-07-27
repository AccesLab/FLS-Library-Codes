#include "ruledialog.h"
#include "ui_ruledialog.h"

ruleDialog::ruleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ruleDialog)
{
    ui->setupUi(this);
}

ruleDialog::~ruleDialog()
{
    delete ui;
}
