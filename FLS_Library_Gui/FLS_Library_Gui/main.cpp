//Author:- Abel Teklu Hailemichael, athailem@aggies.ncat.edu

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
