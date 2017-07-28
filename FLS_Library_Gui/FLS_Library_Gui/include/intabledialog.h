//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef INTABLEDIALOG_H
#define INTABLEDIALOG_H

#include <QDialog>
#include "inputdialog.h"

namespace Ui {
class intableDialog;
}

class intableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit intableDialog(QWidget *parent = 0);
    ~intableDialog();

private slots:
    void on_intableadd_released();

private:
    Ui::intableDialog *ui;
    enum column{
        Name, Range, NumMFs
    };
};

#endif // INTABLEDIALOG_H
