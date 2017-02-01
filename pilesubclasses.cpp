#include "pile.h"
#include "pilesubclasses.h"

PileStock::PileStock(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta=0;//no offest for the stock pile
}

PileFoundation::PileFoundation(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta=0;//no offest for the stock pile
}

PileTableau::PileTableau(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta=20;
}

PileWaste::PileWaste(int x, int y, int dx, int dy, QWidget *parent)
    :Pile(x,y,dx,dy,parent){
    delta=0;//no offest for the stock pile
}
