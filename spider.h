#ifndef SPIDER_H
#define SPIDER_H
#include"game.h"
#include <QWidget>
class Pile;

class Spider:public Game
{
    Pile *deal;
    Pile *waste;
    Pile *foundation[4];
    Pile *tableau[7];
public:
    Spider(QWidget *par);
    ~Spider();
    void ReDeal(hardtype h=EASY);
};

#endif // SPIDER_H
