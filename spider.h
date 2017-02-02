#ifndef SPIDER_H
#define SPIDER_H
#include"game.h"
#include <QWidget>
class Pile;

class Spider:public Game
{
    Pile *deal;
    Pile *foundation[7];
    Pile *tableau[10];
private:
   void CreatePile();
public:
    Spider(QWidget *par);
    ~Spider();
    void ReDeal(hardtype h=EASY);
     QString GameName(){return 0;}
};

#endif // SPIDER_H
