#include "spider.h"
#include "pile.h"
#include "pilesubclasses.h"
#include "card.h"

Spider::Spider(QWidget *par):Game(par)
{

}

Spider::~Spider(){

}

void Spider::CreatePile(){
    //create piles
    const int span = 30;
    for(int i = 0 ; i < 10; i++){
        tableau[i] = new PileTableau(30+(span+71)*i,30,71,96,parent);
    }
    for(int i = 0 ; i < 8; i++){
        foundation[i] = new PileFoundation(30+(span+71)*i,500,71,96,parent);
    }
    deal = new PileStock(950,500,71,96,parent);
    //add them to parent
    AddPile(deal);
    for(int i = 0 ; i < 8; i++){
        AddPile(foundation[i]);
    }
    for(int i = 0 ; i < 10; i++){
        AddPile(tableau[i]);
    }
}


void Spider::ReDeal(hardtype h){
    Clear();
    CreatePile();
    Card* deck[104];
    for(int i = CLUBS; i<= SPADES;i++){

        for(int j=ACE; j<=KING;j++){

            deck[i*SUIT_SIZE+j]=new Card((pips)j,(suits)i,parent);
        }
    }
    for(int i = CLUBS; i<= SPADES;i++){

        for(int j=ACE; j<=KING;j++){

            deck[52+i*SUIT_SIZE+j]=new Card((pips)j,(suits)i,parent);
        }
    }
    Shuffle(deck,sizeof(deck)/sizeof(Card *));
    int pointer=103;
    for(int i=0;i<10;i++){
        for(int j=0;j<6 && i<4||j<5 && i<10;j++){
            deck[pointer--]->Move(tableau[i], (j==5&&i<4||j==4&&i>=4)? true : false);// expose the card on top
        }
    }
    for(int i=0;i<=pointer;i++){
//        deal->appendCard(deck[i]);
        deck[i]->Move(deal, false);
    }
}


