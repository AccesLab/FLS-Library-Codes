//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef OUTPUTDIALOG_H
#define OUTPUTDIALOG_H

#include <QDialog>
#include "outmfsdialog.h"

namespace Ui {
class outputDialog;
}

class outputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outputDialog(QWidget *parent = 0);
    ~outputDialog();

    QString outName() const;
    QString outRange() const;
    int outNumMFs() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_addMF_released();

private:
    Ui::outputDialog *ui;
    enum column{
        Name, Type, P1, P2, P3, P4, Maximum, TSKC
    };
};

#endif // OUTPUTDIALOG_H
