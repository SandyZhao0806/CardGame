#ifndef SPIDER_H
#define SPIDER_H
#include"game.h"
#include <QWidget>
class Pile;

class Spider:public Game
{
    Pile *deal;
    Pile *foundation[8];
    Pile *tableau[10];
private:
   void CreatePile();
public:
    Spider(QWidget *par);
    ~Spider();
    void ReDeal(hardtype h=EASY);
    void OnDealClick(Card *);
    void OnFiledClick(Card *c);
    void OnDealtClick(Card *c);
     QString GameName(){return "Spider";}
};

#endif // SPIDER_H
