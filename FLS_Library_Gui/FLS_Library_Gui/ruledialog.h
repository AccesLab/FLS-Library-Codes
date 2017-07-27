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

private:
    Ui::ruleDialog *ui;
};

#endif // RULEDIALOG_H
