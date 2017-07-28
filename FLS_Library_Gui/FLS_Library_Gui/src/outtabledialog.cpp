//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "outtabledialog.h"
#include "ui_outtabledialog.h"

outtableDialog::outtableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outtableDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Output Name"<< "Range" << "MFs";
    ui->outtableWidget->setColumnCount(3);
    ui->outtableWidget->setHorizontalHeaderLabels(titles);
}

outtableDialog::~outtableDialog()
{
    delete ui;
}

void outtableDialog::on_outtableadd_released()
{

    int res;
    QString outpname;
    QString outprange;
    int outpMFs;

    outputDialog outdialog;
    outdialog.setWindowTitle("Add FLS Output");
    outdialog.setModal(true);
    res = outdialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    outpname = outdialog.outName();
    outprange = outdialog.outRange();
    outpMFs = outdialog.outNumMFs();

    ui->outtableWidget->insertRow((ui->outtableWidget->rowCount()));
    ui->outtableWidget->setItem(ui->outtableWidget->rowCount() - 1, Name, new QTableWidgetItem(outpname));
    ui->outtableWidget->setItem(ui->outtableWidget->rowCount() - 1, Range, new QTableWidgetItem(outprange));
    ui->outtableWidget->setItem(ui->outtableWidget->rowCount() - 1, NumMFs, new QTableWidgetItem(QString::number(outpMFs)));
}
