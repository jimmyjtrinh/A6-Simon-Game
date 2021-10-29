/*
 * Jimmy Trinh && Jacob Day
 * Software Practice II, CS 3505
 * A6: Qt Simon Game
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //sets buttons default to a deeper red and changes color when pressed
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

    //activates all the losing screen when a player loses
    ui->loseLabel->setVisible(false);
    ui->highScoreLabel->setVisible(false);
    ui->scoreLabel->setVisible(false);
    ui->lastGameScoreLabel->setVisible(false);
    ui->lastScoreLabel->setVisible(false);

    // connects all the signals to losing implementation
    connect(&model, &Model::loseSignal, ui->loseLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->highScoreLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->scoreLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->lastGameScoreLabel, &QLabel::setVisible);
    connect(&model, &Model::loseSignal, ui->lastScoreLabel, &QLabel::setVisible);
    connect(&model, &Model::updateScoreSignal, ui->scoreLabel, &QLabel::setText);
    connect(&model, &Model::lastScoreSignal, ui->lastScoreLabel, &QLabel::setText);

    //connecting the updateView signal emission with the progress bar in UI
    connect(&model, &Model::updateProgress, ui->progressBar, &QProgressBar::setValue);

    //enabling/disabling the three buttons at appropriate times
    connect(&model, &Model::enableRedBlueButtons, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &Model::enableRedBlueButtons, ui->blueButton, &QPushButton::setEnabled);
    connect(&model, &Model::enableStartButton, ui->startButton, &QPushButton::setEnabled);

    //showing the order of the game by changing the color of the buttons
    connect(&model, &Model::redSignal, ui->redButton, &QPushButton::setStyleSheet);
    connect(&model, &Model::blueSignal, ui->blueButton, &QPushButton::setStyleSheet);

    //connecting the red/blue buttons with the red/blue push method inside the model
    connect(ui->redButton, &QPushButton::clicked, &model, &Model::redPush);
    connect(ui->blueButton, &QPushButton::clicked, &model, &Model::bluePush);

    //connecting our start button with the gameStart method that will start the game
    connect(ui->startButton, &QPushButton::clicked, &model, &Model::gameStart);
}

MainWindow::~MainWindow()
{
    delete ui;
}



