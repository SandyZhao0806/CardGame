#include "pile.h"
#include "card.h"
#include "gameboard.h"
#include "cardmove.h"


extern gameboard *MainApp;
extern Game *game;
extern QList<Pile *> piles;

// static member data allocation
//Rule *PileStock::dragRules[DRAGLAST];
//Rule *PileStock::dropRules[DROPLAST];

//Rule *PileFoundation::dragRules[DRAGLAST];
//Rule *PileFoundation::dropRules[DROPLAST];

//Rule *PileTableau::dragRules[DRAGLAST];
//Rule *PileTableau::dropRules[DROPLAST];

//Rule *PileFreeCell::dragRules[DRAGLAST];
//Rule *PileFreeCell::dropRules[DROPLAST];


//Rule *PileWaste::dragRules[DRAGLAST];

// constructor
Pile::Pile(int x, int y, int dx, int dy, QWidget *parent):
    QLabel(parent),delta(QPoint(dx,dy)),top(0),bottom(0)
{
        setParent(parent);
        setFrameShape(Box);
        resize(dx,dy);
        move(x,y);
        setLineWidth(2);
        show();
    //TODO
}
Pile::~Pile()
{
    //TODO
}

void Pile::appendCard(Card *c){
    if(!top){
        top = c;
    }else{
        top->setOver(c);
        c->setUnder(top);
        top=c;
    }
    if(!bottom){
        bottom=top;
    }
}
