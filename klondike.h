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
private:
   void CreatePile();
public:
    Klondike(QWidget *par);
    ~Klondike();
    void ReDeal(hardtype h=EASY);
    QString GameName(){return "Klondike";}
//    void DealAction();
    void OnFiledClick(Card *c);
    void OnDealtClick(Card *c);
    void OnDealClick(Card *);
    void OnEmptyDealClick();

};

#endif // KLONDIKE_H
