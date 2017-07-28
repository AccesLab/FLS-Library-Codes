//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef OUTTABLEDIALOG_H
#define OUTTABLEDIALOG_H

#include <QDialog>
#include "outputdialog.h"

namespace Ui {
class outtableDialog;
}

class outtableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outtableDialog(QWidget *parent = 0);
    ~outtableDialog();

private slots:
    void on_outtableadd_released();

private:
    Ui::outtableDialog *ui;
    enum column{
        Name, Range, NumMFs
    };
};

#endif // OUTTABLEDIALOG_H
