#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

    ui->loseLabel->setVisible(false);
    ui->highScoreLabel->setVisible(false);
    ui->scoreLabel->setVisible(false);
    ui->lastGameScoreLabel->setVisible(false);
    ui->lastScoreLabel->setVisible(false);

    connect(&model, &Model::loseSignal, ui->loseLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->highScoreLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->scoreLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->lastGameScoreLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->lastScoreLabel, &QLabel::setVisible);
    connect(&model, &Model::updateScoreSignal, ui->scoreLabel, &QLabel::setText);
    connect(&model, &Model::lastScoreSignal, ui->lastScoreLabel, &QLabel::setText);


    //connecting the updateView signal emission with the progress bar in UI
    connect(&model, &Model::updateView, ui->progressBar, &QProgressBar::setValue);

    //enabling buttons when the game starts
    connect(&model, &Model::enableRedBlueButtons, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &Model::enableRedBlueButtons, ui->blueButton, &QPushButton::setEnabled);

    connect(&model, &Model::redSignal, ui->redButton, &QPushButton::setStyleSheet);
    connect(&model, &Model::blueSignal, ui->blueButton, &QPushButton::setStyleSheet);


    //connecting our start button with the gameStart method that will start the game
    connect(ui->startButton, &QPushButton::clicked, &model, &Model::gameStart);

    connect(&model, &Model::enableStartButton, ui->startButton, &QPushButton::setEnabled);




    //connecting redButton with the redPush method inside the model
    connect(ui->redButton, &QPushButton::pressed, &model, &Model::redPush);

    //connecting blueButton with the bluePush method inside the model
    connect(ui->blueButton, &QPushButton::pressed, &model, &Model::bluePush);
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

