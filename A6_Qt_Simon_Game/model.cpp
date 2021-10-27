#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    progress = 0;
    highScore = 0;
    delay = 1500;
}

void Model::gameStart(){
    expectedOrder.clear();
    playerOrder.clear();
    emit loseSignal(false);
    for(int i = 0; i < 3; i ++)
    {
        expectedOrder.enqueue(rand() % 2);
    }
    emit enableStartButton(false);
    timer.singleShot(1000, this, &Model::showOrder);
}



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

void Model::enableButtons(){
    emit enableRedBlueButtons(true);
}

void Model::showProgress(){
    progress = ((playerOrder.length() * 1.0) / (expectedOrder.length() * 1.0)) * 100;
    emit updateView(progress);
}

void Model::showRed(){
    emit redSignal(QString("QPushButton {background-color: rgb(255,150,150);}"));
    timer.singleShot(delay - 200, this, &Model::stopShowingRed);
}

void Model::showBlue(){
    emit blueSignal(QString("QPushButton {background-color: rgb(150,150,255);}"));
    timer.singleShot(delay - 200, this, &Model::stopShowingBlue);
}

void Model::stopShowingRed(){
    emit redSignal(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

void Model::stopShowingBlue(){
    emit blueSignal(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

}

void Model::redPush(){
    playerOrder.enqueue(0);
    updateGame(playerOrder.length() - 1);
}

void Model::bluePush(){
    playerOrder.enqueue(1);
    updateGame(playerOrder.length() - 1);
}

void Model::updateGame(int i){
    if(expectedOrder[i] != playerOrder[i])
    {
        if(highScore < expectedOrder.length()){
            highScore = expectedOrder.length();
            emit updateScoreSignal(QString::number(highScore));
        }
        emit lastScoreSignal(QString::number(expectedOrder.length()));
        emit enableRedBlueButtons(false);
        emit loseSignal(true);
        emit enableStartButton(true);
    }

    showProgress();
    if(expectedOrder.length() == playerOrder.length())
    {
        emit enableRedBlueButtons(false);
        playerOrder.clear();
        expectedOrder.enqueue(rand() % 2);
        timer.singleShot(1000, this, &Model::showOrder);
    }
}
