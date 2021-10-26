#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data = 0;  //may want to remove later ********************************************
    connect(this, &MainWindow::updateData, ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_redButton_pressed()
{
    data +=10;
    emit updateData(data);
}


void MainWindow::on_blueButton_pressed()
{
    data +=10;
    emit updateData(data);
}


void MainWindow::on_startButton_clicked()
{
    ui->redButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
}

