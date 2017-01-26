#include "pile.h"
#include "card.h"
#include "gameboard.h"
#include "cardmove.h"

#if(0)
extern GameBoard *MainApp;
extern Game *game;
extern QList<Pile *> piles;

// static member data allocation
Rule *PileStock::dragRules[DRAGLAST];
Rule *PileStock::dropRules[DROPLAST];

Rule *PileFoundation::dragRules[DRAGLAST];
Rule *PileFoundation::dropRules[DROPLAST];

Rule *PileTableau::dragRules[DRAGLAST];
Rule *PileTableau::dropRules[DROPLAST];

Rule *PileFreeCell::dragRules[DRAGLAST];
Rule *PileFreeCell::dropRules[DROPLAST];


Rule *PileWaste::dragRules[DRAGLAST];

// constructor
Pile::Pile(int x, int y, int dx, int dy, QWidget *parent):
    QLabel(parent),delta(QPoint(dx,dy)),top(0),bottom(0)
{
    //TODO
}
Pile::~Pile()
{
    //TODO
}
#endif
