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

private slots:
    void on_addMF_released();

private:
    Ui::inputDialog *ui;
};

#endif // INPUTDIALOG_H
