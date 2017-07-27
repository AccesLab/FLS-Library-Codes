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

private:
    Ui::outputDialog *ui;
};

#endif // OUTPUTDIALOG_H
