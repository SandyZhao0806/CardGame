#ifndef KLONDIKE_H
#define KLONDIKE_H
#include"game.h"
#include <QWidget>
class Pile;

class Klondike: public Game
{
   Pile *deal;
   Pile *waste;
   Pile *foundation[4];
   Pile *tableau[7];
public:
    Klondike(QWidget *par);
    ~Klondike();
    void ReDeal(hardtype h=EASY);
    QString GameName(){return 0;}
//    void DealAction();
//    void OnFiledClick(Card *c);
//    void OnDealClick(Card *);
//    void OnDealtClick(Card *c);
};

#endif // KLONDIKE_H
