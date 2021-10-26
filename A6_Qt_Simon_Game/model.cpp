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

    for(auto number : order)
    {
        switch (number){
            case 0:
                timer.singleShot(1000, this, &Model::addOne);
//                timer.singleShot(1000, this, [](){showOrder(number);});


                break;
            case 1:
                break;
        }
    }


    emit startGame(true);
}

void Model::addOne(){
    data +=1;
    emit updateView(data);
}

void Model::showOrder(int number){

}
