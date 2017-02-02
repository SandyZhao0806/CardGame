#include "freecell.h"
#include "pile.h"
#include "pilesubclasses.h"
#include "card.h"

FreeCell::FreeCell(QWidget *par):Game(par)
{

}

FreeCell::~FreeCell(){

}

void FreeCell::CreatePile(){
    //create piles
    const int span = 30;
    for(int i = 0 ; i < 4; i++){
        freecell[i] = new PileFreeCell(30+(span+71)*i,30,71,96,parent);
    }
    for(int i = 0 ; i < 4; i++){
        foundation[i] = new PileFoundation(434+(span+71)*i,30,71,96,parent);
    }
    for(int i = 0 ; i < 8; i++){
        tableau[i] = new PileTableau(30+(span+71)*i,200,71,96,parent);
    }
    //add them to parent
    for(int i = 0 ; i < 4; i++){
        AddPile(freecell[i]);
    }
    for(int i = 0 ; i < 4; i++){
        AddPile(foundation[i]);
    }
    for(int i = 0 ; i < 8; i++){
        AddPile(tableau[i]);
    }
}


void FreeCell::ReDeal(hardtype h){
    Clear();
    CreatePile();
    Card* deck[52];
    for(int i = CLUBS; i<= SPADES;i++){

        for(int j=ACE; j<=KING;j++){

            deck[i*SUIT_SIZE+j]=new Card((pips)j,(suits)i,parent);
        }
    }

    Shuffle(deck,sizeof(deck)/sizeof(Card *));
    int pointer=51;
    for(int i=0;i<sizeof(tableau)/sizeof(Pile *);i++){
        for(int j=0;j<7&&i<4||j<6&&i<sizeof(tableau)/sizeof(Pile *);j++){
//            tableau[i]->appendCard(deck[pointer--]);
            deck[pointer--]->Move(tableau[i],true);// expose the card on top
        }
    }
}

