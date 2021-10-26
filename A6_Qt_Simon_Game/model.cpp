#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    data = 0;
}

void Model::gameStart(){
    for(int i = 0; i < 3; i ++)
    {
        order.enqueue(rand() % 2);
    }


    for(int i = 0; i < order.length(); i ++)
    {
        switch(order[i])
        {
        case 0:
            timer.singleShot(1250 * i, this, &Model::showRed);
            break;
        case 1:
            timer.singleShot(1250 * i, this, &Model::showBlue);
            break;
        }
    }

//    for(auto number : order)
//    {
//        switch (number){
//            case 0:
//                timer.singleShot(1000, this, &Model::addOne);


//                break;
//            case 1:
//                break;
//        }
//    }


    emit startGame(true);
}

void Model::addOne(){
    data +=1;
    emit updateView(data);
}

void Model::showRed(){
    cout << "red" << endl;
    emit redSignal(QString("QPushButton {background-color: rgb(255,150,150);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    timer.singleShot(1000, this, &Model::stopShowingRed);
}

void Model::showBlue(){
    cout << "blue" << endl;
    emit blueSignal(QString("QPushButton {background-color: rgb(150,150,255);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    timer.singleShot(1000, this, &Model::stopShowingBlue);
}

void Model::stopShowingRed(){
    emit redSignal(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

void Model::stopShowingBlue(){
    emit blueSignal(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

}
