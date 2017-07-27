#ifndef OUTMFSDIALOG_H
#define OUTMFSDIALOG_H

#include <QDialog>

namespace Ui {
class outMFsDialog;
}

class outMFsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outMFsDialog(QWidget *parent = 0);
    ~outMFsDialog();

private slots:
    void on_buttonBox_2_accepted();

private:
    Ui::outMFsDialog *ui;
};

#endif // OUTMFSDIALOG_H
