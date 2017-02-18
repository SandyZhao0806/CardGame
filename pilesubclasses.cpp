#include "pile.h"
#include "card.h"
#include "pilesubclasses.h"

PileStock::PileStock(int x, int y, int dx, int dy, QWidget *parent, Game *game)
    :Pile(x,y,dx,dy,parent,game){
    delta.setX(0);//no offest for the stock pile
    delta.setY(0);
}
/*
 * call corresponding function of Game class
 */
void PileStock::onClickEvent(Card * c){
    game->OnDealClick(c);
}

// static member data allocation
Rule *PileStock::dragRules[DRAGLAST];
Rule *PileStock::dropRules[DROPLAST];

void PileStock::DragRule(int i, Rule *r){
    dragRules[i]=r;
}

void PileStock::DropRule(int i, Rule *r){
    dropRules[i]=r;
}

Rule* PileStock:: DragRule(int i){
    return dragRules[i];
}

Rule* PileStock::DropRule(int i){
    return dropRules[i];
}

pileType PileStock::Type(){
    return STOCK;
}

PileFoundation::PileFoundation(int x, int y, int dx, int dy, QWidget *parent, Game *game)
    :Pile(x,y,dx,dy,parent,game){
    delta.setX(0);//no offest for the foundation pile
    delta.setY(0);
}


Rule *PileFoundation::dragRules[DRAGLAST];
Rule *PileFoundation::dropRules[DROPLAST];

void PileFoundation::DragRule(int i, Rule *r){
    dragRules[i]=r;
}

void PileFoundation::DropRule(int i, Rule *r){
    dropRules[i]=r;
}

Rule* PileFoundation:: DragRule(int i){
    return dragRules[i];
}

Rule* PileFoundation::DropRule(int i){
    return dropRules[i];
}

pileType PileFoundation::Type(){
    return FOUNDATION;
}

PileTableau::PileTableau(int x, int y, int dx, int dy, QWidget *parent, Game *game)
    :Pile(x,y,dx,dy,parent,game){
    delta.setX(0);
    delta.setY(20);
}

void PileTableau::onClickEvent(Card * c){
    game->OnFiledClick(c);
}

Rule *PileTableau::dragRules[DRAGLAST];
Rule *PileTableau::dropRules[DROPLAST];

void PileTableau::DragRule(int i, Rule *r){
    dragRules[i]=r;
}

void PileTableau::DropRule(int i, Rule *r){
    dropRules[i]=r;
}

Rule* PileTableau:: DragRule(int i){
    return dragRules[i];
}

Rule* PileTableau::DropRule(int i){
    return dropRules[i];
}

pileType PileTableau::Type(){
    return TABLEAU;
}

PileFreeCell::PileFreeCell(int x, int y, int dx, int dy, QWidget *parent, Game *game)
     :Pile(x,y,dx,dy,parent,game){
    delta.setX(0);//no offest for the waste pile
    delta.setY(0);
    }

void PileFreeCell::onClickEvent(Card * c){
    game->OnFreeCellClick(c);
}


Rule *PileFreeCell::dragRules[DRAGLAST];
Rule *PileFreeCell::dropRules[DROPLAST];

void PileFreeCell::DragRule(int i, Rule *r){
    dragRules[i]=r;
}

void PileFreeCell::DropRule(int i, Rule *r){
    dropRules[i]=r;
}

Rule* PileFreeCell:: DragRule(int i){
    return dragRules[i];
}

Rule* PileFreeCell::DropRule(int i){
    return dropRules[i];
}

pileType PileFreeCell::Type(){
    return FREE_CELL;
}

PileWaste::PileWaste(int x, int y, int dx, int dy, QWidget *parent, Game *game)
    :Pile(x,y,dx,dy,parent,game){
    delta.setX(0);//no offest for the waste pile
    delta.setY(0);
}

void PileWaste::onClickEvent(Card * c){
    game->OnDealtClick(c);
}

Rule *PileWaste::dragRules[DRAGLAST];
Rule *PileWaste::dropRules[DRAGLAST];

void PileWaste::DragRule(int i, Rule *r){
    dragRules[i]=r;
}

void PileWaste::DropRule(int i, Rule *r){
    dropRules[i]=r;
}

Rule* PileWaste:: DragRule(int i){
    return dragRules[i];
}

Rule* PileWaste::DropRule(int i){
    return dropRules[i];
}

pileType PileWaste::Type(){
    return WASTE;
}
