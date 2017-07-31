//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "ruledialog.h"
#include "ui_ruledialog.h"

ruleDialog::ruleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ruleDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Antecedents" << "Consequents" << "Inference (And/Or)" << "Weight";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

ruleDialog::~ruleDialog()
{
    delete ui;
}

void ruleDialog::on_buttonBox_accepted()
{
    accept();
}

void ruleDialog::on_buttonBox_rejected()
{
    reject();
}

void ruleDialog::on_pushButton_released()
{
    int res;
    QString rant;
    QString rcons;
    QString rinf;
    double rweight;


    addrulesDialog rdialog;
    rdialog.setWindowTitle("Add Rule");
    rdialog.setModal(true);
    res = rdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    rant = rdialog.anticident();
    rcons = rdialog.consequent();
    rinf = rdialog.andor();
    rweight = rdialog.weight();


    ui->tableWidget->insertRow((ui->tableWidget->rowCount()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Anticident, new QTableWidgetItem(rant));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Conseqient, new QTableWidgetItem(rcons));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, AndOr, new QTableWidgetItem(rinf));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Weight, new QTableWidgetItem(QString::number(rweight)));

}


