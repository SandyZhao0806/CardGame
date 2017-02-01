#include "pile.h"
#include "card.h"
#include "pilesubclasses.h"

PileStock::PileStock(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the stock pile
    delta.setY(0);
}
void PileStock::appendCard(Card *c){
    Pile::appendCard(c);
}

PileFoundation::PileFoundation(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the stock pile
    delta.setY(0);
}

PileTableau::PileTableau(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);
    delta.setY(20);
}
void PileTableau::appendCard(Card *c){
    Pile::appendCard(c);
    if(top)
        top->Faceup(false);
    Pile::appendCard(c);
    top->Faceup(true);
}

PileWaste::PileWaste(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the stock pile
    delta.setY(0);
}
