//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "intabledialog.h"
#include "ui_intabledialog.h"

intableDialog::intableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intableDialog)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "Input Name"<< "Range"<<"MFs";
    ui->intableWidget->setColumnCount(3);
    ui->intableWidget->setHorizontalHeaderLabels(titles);
}

intableDialog::~intableDialog()
{
    delete ui;
}

void intableDialog::on_intableadd_released()
{
    int res;
    QString inpname;
    QString inprange;
    int inpMFs;

    inputDialog indialog;
    indialog.setWindowTitle("Add FLS Input");
    indialog.setModal(true);
    res = indialog.exec();
    if(res == QDialog::Rejected){
        return;
    }

    inpname = indialog.inName();
    inprange = indialog.inRange();
    inpMFs = indialog.inNumMFs();

    ui->intableWidget->insertRow((ui->intableWidget->rowCount()));
    ui->intableWidget->setItem(ui->intableWidget->rowCount() - 1, Name, new QTableWidgetItem(inpname));
    ui->intableWidget->setItem(ui->intableWidget->rowCount() - 1, Range, new QTableWidgetItem(inprange));
    ui->intableWidget->setItem(ui->intableWidget->rowCount() - 1, NumMFs, new QTableWidgetItem(QString::number(inpMFs)));
}
