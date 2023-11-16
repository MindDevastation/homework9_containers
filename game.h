#ifndef GAME_H
#define GAME_H

#include <QString>
#include <list>
#include <queue>
#include <math.h>

class Game
{
    QString _score;
    int _result = 0;
public:
    Game();

    int getResult();
    void setResult(int newResult);

    QString getScore();
    void setScore(QString newScore);

    void sumScore();
};

#endif // GAME_H
