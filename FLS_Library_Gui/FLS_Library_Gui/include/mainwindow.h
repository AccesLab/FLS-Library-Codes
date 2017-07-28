//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "intabledialog.h"
#include "outtabledialog.h"
#include "ruledialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
