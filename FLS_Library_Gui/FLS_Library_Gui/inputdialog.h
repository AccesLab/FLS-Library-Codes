//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include "inmfsdialog.h"

namespace Ui {
class inputDialog;
}

class inputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inputDialog(QWidget *parent = 0);
    ~inputDialog();

    QString inName() const;
    QString inRange() const;
    int inNumMFs() const;

private slots:
    void on_addMF_released();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::inputDialog *ui;
    enum column{
        Name, Type, P1, P2, P3, P4, Maximum
    };
};

#endif // INPUTDIALOG_H
