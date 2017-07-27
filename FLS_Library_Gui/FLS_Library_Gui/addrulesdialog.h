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

private:
    Ui::addrulesDialog *ui;
};

#endif // ADDRULESDIALOG_H
