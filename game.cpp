#include "game.h"
#include "pile.h"
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
        parent->layout()->removeWidget(piles.at(i));
        delete piles.at(i);
    }
}

void Game::AddPile(Pile *p){
    parent->layout()->addWidget(p);
    piles.append(p);
}
