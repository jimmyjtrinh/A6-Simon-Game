/*
 * Jimmy Trinh && Jacob Day
 * Software Practice II, CS 3505
 * A6: Qt Simon Game
 */
#include "model.h"

/**
 * @brief Model::Model Constructor for our model class
 * @param parent
 */
Model::Model(QObject *parent) : QObject(parent)
{
    progress = 0;
    highScore = 0;
    delay = 1500;
}

/**
 * @brief Model::gameStart starts the first 3 sequence of the game.
 * First clears out the current state of the model.
 */
void Model::gameStart(){
    expectedOrder.clear();
    playerOrder.clear();
    emit loseSignal(false);

    //add the first three game sequence
    for(int i = 0; i < 3; i ++)
    {
        expectedOrder.enqueue(rand() % 2);
    }
    emit enableStartButton(false);
    timer.singleShot(1000, this, &Model::showOrder);
}

/**
 * @brief Model::showOrder Displays the game squence to the view with either red or blue flashes
 */
void Model::showOrder(){
    if(delay > 300){
        delay = 1500 - (100 * expectedOrder.length());
    }
    emit enableRedBlueButtons(false);

    timer.singleShot(delay * (expectedOrder.length()) + 1, this, &Model::enableButtons);
    for(int i = 0; i < expectedOrder.length(); i ++)
    {
        switch(expectedOrder[i])
        {
        case 0:
            timer.singleShot(delay * i, this, &Model::showRed);
            break;
        case 1:
            timer.singleShot(delay * i, this, &Model::showBlue);
            break;
        }
    }
    showProgress();
}

/**
 * @brief Model::enableButtons Letting the player access the blue blue button
 */
void Model::enableButtons(){
    emit enableRedBlueButtons(true);
}

/**
 * @brief Model::showProgress Updates the progress bar in the view
 */
void Model::showProgress(){
    progress = ((playerOrder.length() * 1.0) / (expectedOrder.length() * 1.0)) * 100;
    emit updateProgress(progress);
}

/**
 * @brief Model::showRed changes red button to light red
 */
void Model::showRed(){
    emit redSignal(QString("QPushButton {background-color: rgb(255,150,150);}"));
    timer.singleShot(delay - 200, this, &Model::stopShowingRed);
}

/**
 * @brief Model::showBlue changes blue button to light blue
 */
void Model::showBlue(){
    emit blueSignal(QString("QPushButton {background-color: rgb(150,150,255);}"));
    timer.singleShot(delay - 200, this, &Model::stopShowingBlue);
}

/**
 * @brief Model::stopShowingRed changes red button back to default red
 */
void Model::stopShowingRed(){
    emit redSignal(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

/**
 * @brief Model::stopShowingBlue changes blue button back to default blue
 */
void Model::stopShowingBlue(){
    emit blueSignal(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

/**
 * @brief Model::redPush input from the user for pushing the red button
 */
void Model::redPush(){
    playerOrder.enqueue(0);
    updateGame(playerOrder.length() - 1);
}

/**
 * @brief Model::bluePush input from the user for pushing the blue button
 */
void Model::bluePush(){
    playerOrder.enqueue(1);
    updateGame(playerOrder.length() - 1);
}

/**
 * @brief Model::updateGame updates the current game model
 * @param i current index of the game
 */
void Model::updateGame(int i){

    //if the last sequence of the player input does not match our expected order of the game, they will lose
    if(expectedOrder[i] != playerOrder[i])
    {
        if(highScore < expectedOrder.length()){
            highScore = expectedOrder.length();
            emit updateScoreSignal(QString::number(highScore));
        }
        //enables all the lose screen and allows player to restart
        emit lastScoreSignal(QString::number(expectedOrder.length()));
        emit enableRedBlueButtons(false);
        emit loseSignal(true);
        emit enableStartButton(true);
    }
    showProgress();
    //if the player hits the correct sequence, update the game model
    if(expectedOrder.length() == playerOrder.length())
    {
        emit enableRedBlueButtons(false);
        playerOrder.clear();
        expectedOrder.enqueue(rand() % 2);
        timer.singleShot(1000, this, &Model::showOrder);
    }
}
