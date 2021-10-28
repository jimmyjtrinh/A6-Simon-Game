/*
 * Jimmy Trinh && Jacob Day
 * Software Practice II, CS 3505
 * A6: Qt Simon Game
 */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("QMainWindow {background-color: rgb(247, 250, 157);}");
    w.show();
    return a.exec();
}
