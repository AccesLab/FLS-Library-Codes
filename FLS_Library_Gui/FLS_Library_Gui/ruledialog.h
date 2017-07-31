//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef RULEDIALOG_H
#define RULEDIALOG_H

#include <QDialog>
#include "addrulesdialog.h"

namespace Ui {
class ruleDialog;
}

class ruleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ruleDialog(QWidget *parent = 0);
    ~ruleDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_released();

private:
    Ui::ruleDialog *ui;
    enum column{
        Anticident, Conseqient, AndOr, Weight
    };
};

#endif // RULEDIALOG_H
