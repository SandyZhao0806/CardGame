#include "pile.h"
#include "card.h"
#include "pilesubclasses.h"

PileStock::PileStock(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the stock pile
    delta.setY(0);
}

PileFoundation::PileFoundation(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the foundation pile
    delta.setY(0);
}

PileTableau::PileTableau(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);
    delta.setY(40);
}

PileFreeCell::PileFreeCell(int x, int y, int dx, int dy, QWidget *parent)
     :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the waste pile
    delta.setY(0);
    }
PileWaste::PileWaste(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta.setX(0);//no offest for the waste pile
    delta.setY(0);
}
