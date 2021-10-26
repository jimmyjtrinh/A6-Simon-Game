#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connecting the updateView signal emission with the progress bar in UI
    connect(&model, &Model::updateView, ui->progressBar, &QProgressBar::setValue);

    //enabling buttons when the game starts
    connect(&model, &Model::startGame, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &Model::startGame, ui->blueButton, &QPushButton::setEnabled);


    //connecting our start button with the gameStart method that will start the game
    connect(ui->startButton, &QPushButton::clicked, &model, &Model::gameStart);




    //connecting redButton with the add one method inside the model
    connect(ui->redButton, &QPushButton::pressed, &model, &Model::addOne);

    //connecting blueButton with the add one method inside the model
    connect(ui->blueButton, &QPushButton::pressed, &model, &Model::addOne);
}

MainWindow::~MainWindow()
{
    delete ui;
}





//void MainWindow::on_startButton_clicked()
//{
//    ui->redButton->setEnabled(true);
//    ui->blueButton->setEnabled(true);
//}

