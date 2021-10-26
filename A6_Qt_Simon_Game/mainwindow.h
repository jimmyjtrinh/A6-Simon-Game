#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_redButton_pressed();


    void on_blueButton_pressed();

    void on_startButton_clicked();

signals:
    void updateData(int);

private:
    Ui::MainWindow *ui;
    Model model;

    int data; //******************** want to modify later to be in the model or delete***************************
};
#endif // MAINWINDOW_H
