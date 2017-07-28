//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef ADDRULESDIALOG_H
#define ADDRULESDIALOG_H

#include <QDialog>

namespace Ui {
class addrulesDialog;
}

class addrulesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addrulesDialog(QWidget *parent = 0);
    ~addrulesDialog();

    QString anticident() const;
    QString consequent() const;
    QString andor() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addrulesDialog *ui;
};

#endif // ADDRULESDIALOG_H
