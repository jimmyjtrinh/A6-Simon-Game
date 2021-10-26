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
    void showRed();
    void stopShowingRed();
    void showBlue();
    void stopShowingBlue();

signals:
    void updateView(int);
    void startGame(bool);
    void redSignal(QString);
    void blueSignal(QString);

private:
    int data;
    QQueue<int> order;
    QTimer timer;

};

#endif // MODEL_H
