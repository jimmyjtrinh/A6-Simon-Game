/*
 * Jimmy Trinh && Jacob Day
 * Software Practice II, CS 3505
 * A6: Qt Simon Game
 */
#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <stdlib.h>
#include <QQueue>
#include <QTimer>

using std::rand;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

//used with the view
public slots:
    void gameStart(); //starts the sequence of the game
    void redPush(); //input from user
    void bluePush(); //input from user

//internal model slots
private slots:
    void showProgress(); //updates the progress bar
    void showOrder(); //displays the sequence to the view
    void enableButtons(); //enable red/blue buttons
    void showRed(); //changes red button to light red
    void stopShowingRed(); //changes red button back to default red
    void showBlue(); //changes blue button to light blue
    void stopShowingBlue(); //changes blue button back to default blue
    void updateGame(int); //updates the current game model

signals:
    void updateProgress(int);
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
