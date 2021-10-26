#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void addOne();
    void gameStart();

signals:
    void updateView(int);
    void startGame(bool);

private:
    int data;

};

#endif // MODEL_H
