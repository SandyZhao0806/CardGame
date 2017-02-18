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
        freecell[i] = new PileFreeCell(30+(span+71)*i,30,71,96,parent,this);
    }
    //These function handles the static arrays. so just call on one object per type
    freecell[0]->AddDragRules(0);
    freecell[0]->AddDropRules(2, new RuleForFreeCell(), new RuleStackOneAtATime());
    for(int i = 0 ; i < 4; i++){
        foundation[i] = new PileFoundation(434+(span+71)*i,30,71,96,parent,this);
    }
    foundation[0]->AddDragRules(1, new RuleStackOneAtATime());
    foundation[0]->AddDropRules(4,new RuleBaseAce(),new RuleMoveSeqDecreasing(), new RuleStackSameSuit(), new RuleStackPlusOne());
    for(int i = 0 ; i < 8; i++){
        tableau[i] = new PileTableau(30+(span+71)*i,200,71,96,parent,this);
    }
    tableau[0]->AddDragRules(2,new RuleMoveSeqIncreasing(), new RuleMoveAltColor());
    tableau[0]->AddDropRules(2,new RuleStackMinusOne(),new RuleStackAlternateColor());
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
    //display piles on the tableau
    for(int i=0;i<sizeof(tableau)/sizeof(Pile *);i++){
        for(int j=0;j<7&&i<4||j<6&&i<sizeof(tableau)/sizeof(Pile *);j++){
            deck[pointer]->Move(tableau[i],true,false);// expose the card on top
            deck[pointer]->raise();// to top
            deck[pointer--]->show();
        }
    }
}

void FreeCell::OnFiledClick(Card *c){
    if(c) PlayOff(c);
}

void FreeCell::OnDealtClick(Card *c){
    if(c) PlayOff(c);
}
