#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    data = 0;
}

void Model::gameStart(){
    emit startGame(true);
}

void Model::addOne(){
    data +=1;
    emit updateView(data);
}
