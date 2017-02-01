#include "klondike.h"
#include "pile.h"
#include "pilesubclasses.h"

Klondike::Klondike(QWidget *par):Game(par)
{
    //create piles
    const int span = 30;
    deal = new PileStock(30,30,71,96,parent);
    waste = new PileWaste(30+71+span,30,71,96,parent);
    for(int i = 0 ; i < 4; i++){
        foundation[i] = new PileFoundation(220+(span+71)*i,30,71,96,parent);
    }
    for(int i = 0 ; i < 7; i++){
        tableau[i] = new PileTableau(30+(span+71)*i,200,71,96,parent);
    }
    //add them to parent
    AddPile(deal);
    AddPile(waste);
    for(int i = 0 ; i < 4; i++){
        AddPile(foundation[i]);
    }
    for(int i = 0 ; i < 7; i++){
        AddPile(tableau[i]);
    }
}

Klondike::~Klondike(){
//    delete[] foundation;
//    delete[] tableau;
}

void Klondike::ReDeal(hardtype h){

}

