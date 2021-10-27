#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    data = 0;
}

void Model::gameStart(){
    for(int i = 0; i < 3; i ++)
    {
        expectedOrder.enqueue(rand() % 2);
    }
    emit disableStartButton(false);
    Model::showOrder();
}



void Model::showOrder(){
    emit enableRedBlueButtons(false);
    timer.singleShot(1250 * (expectedOrder.length()) + 1, this, &Model::enableButtons);
    for(int i = 0; i < expectedOrder.length(); i ++)
    {
        switch(expectedOrder[i])
        {
        case 0:
            timer.singleShot(1250 * i, this, &Model::showRed);
            break;
        case 1:
            timer.singleShot(1250 * i, this, &Model::showBlue);
            break;
        }
    }
}

void Model::enableButtons(){
    emit enableRedBlueButtons(true);
}

void Model::showProgress(){
    data = ((playerOrder.length() * 1.0) / (expectedOrder.length() * 1.0)) * 100;
    cout << "updating progress : " << data  << endl;
    emit updateView(data);
}

void Model::showRed(){
    cout << "red" << endl;
    emit redSignal(QString("QPushButton {background-color: rgb(255,150,150);}"));
    timer.singleShot(1000, this, &Model::stopShowingRed);
}

void Model::showBlue(){
    cout << "blue" << endl;
    emit blueSignal(QString("QPushButton {background-color: rgb(150,150,255);}"));
    timer.singleShot(1000, this, &Model::stopShowingBlue);
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
        //HAHA U LOSE LOOOSER
        emit enableRedBlueButtons(false);

        cout << "WRONG" << endl;
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
