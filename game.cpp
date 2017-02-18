#include "game.h"
#include "pile.h"
#include "cardmove.h"
#include "winningdialog.h"
#include "gameboard.h"
#include "card.h"
#include <QLayout>

Game::Game()
{
    parent = 0;
}

Game::Game(QWidget *parent){
    this->parent = parent;
}

Game::~Game(){
    for(int i = 0 ; i < piles.size() ; i++){
        piles.at(i)->setParent(0);
        delete piles.at(i);
    }
}

// add pile to the array piles
void Game::AddPile(Pile *p){
    piles.append(p);
}

void Game::Clear(){
    CardMove::Clear();// clear the undostack
    while(!piles.empty()){
    Pile *p = piles.takeLast();
    if(p) delete p;
    }
}

//every piles are empty expect the foundation(checking type of pile)
void Game::CheckWin(){
        int  i = piles.count();
        bool allEmpty = true;
        while(allEmpty && i> 0)
            allEmpty = FOUNDATION == piles[--i]->Type() || piles[i]->Empty();
        if(allEmpty)
        {
            WinningDialog *win = new WinningDialog(gb);
            win->exec();//use modal dialog.
            CardMove::Clear();
        }
}

//---------------------------------------------------------------------
bool Game::PlayOff(Card* c)
{
    if(c->Pilep() &&c->Pilep()->CanBeDragged(c))
    {
        int i = 0;
        while(i < piles.count()&& piles[i]&&
              !(piles[i]->Type() == FOUNDATION &&
                piles[i]->CanBeDropped(c)))
            i++;
        if(i < piles.count())
        {
            c->Move(piles[i],true,true,true);
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------
void Game::PlayOffAll()
{
    bool cardFound;
    do
    {
        cardFound = false;
        int n = 0;
        int m = piles.count();
        while(n < m)
        {
            if(piles[n]->Type() > STOCK && piles[n]->Top())
                cardFound = PlayOff(piles[n]->Top());
            n++;
        }
    }while(cardFound);
}
