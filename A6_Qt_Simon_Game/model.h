#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <stdlib.h>
#include <QQueue>
#include <iostream>
#include <QTimer>

using std::rand;
using std::cout;
using std::endl;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void addOne();
    void gameStart();
    void showOrder(int);

signals:
    void updateView(int);
    void startGame(bool);

private:
    int data;
    QQueue<int> order;
    QTimer timer;

};

#endif // MODEL_H
