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
    void showProgress();
    void gameStart();
    void showOrder();
    void enableButtons();
    void showRed();
    void stopShowingRed();
    void showBlue();
    void stopShowingBlue();
    void redPush();
    void bluePush();
    void updateGame(int);

signals:
    void updateView(int);
    void enableRedBlueButtons(bool);
    void enableStartButton(bool);
    void redSignal(QString);
    void blueSignal(QString);
    void loseSignal(bool);
    void updateScoreSignal(QString);
    void lastScoreSignal(QString);

private:
    float progress;
    QQueue<int> expectedOrder;
    QQueue<int> playerOrder;
    QTimer timer;
    float delay;
    int highScore;

};

#endif // MODEL_H
