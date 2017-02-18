#include "klondike.h"
#include "rule.h"
#include "pile.h"
#include "pilesubclasses.h"
#include "card.h"

Klondike::Klondike(QWidget *par):Game(par)
{

}

Klondike::~Klondike(){

}

void Klondike::CreatePile(){
    //create piles
    const int span = 30;
    deal = new PileStock(30,30,71,96,parent,this);
    deal->AddDragRules(1, new RuleStackAny());
    deal->AddDropRules(1,new RuleBaseNone());
    waste = new PileWaste(30+71+span,30,71,96,parent,this);
    waste->AddDragRules(1, new RuleStackOneAtATime());
    waste->AddDropRules(1,new RuleBaseNone());
    for(int i = 0 ; i < 4; i++){
        foundation[i] = new PileFoundation(320+(span+71)*i,30,71,96,parent,this);
    }
    // these function handles the static arrays. so just call on one object per type
    foundation[0]->AddDragRules(1, new RuleStackOneAtATime());
    foundation[0]->AddDropRules(4,new RuleBaseAce(),new RuleMoveSeqDecreasing(), new RuleStackSameSuit(), new RuleStackPlusOne());
    for(int i = 0 ; i < 7; i++){
        tableau[i] = new PileTableau(30+(span+71)*i,200,71,96,parent,this);
    }
    tableau[0]->AddDragRules(2,new RuleMoveSeqIncreasing(), new RuleMoveAltColor());
    tableau[0]->AddDropRules(3,new RuleBaseKing(), new RuleStackMinusOne(),new RuleStackAlternateColor());

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
void Klondike::ReDeal(hardtype h){

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
        for(int j=0;j<=i;j++){
//            tableau[i]->appendCard(deck[pointer--]);
            deck[pointer]->Move(tableau[i], j == i ? true : false, false);// expose the card on top
            deck[pointer]->raise();// to top
            deck[pointer--]->show();

        }
    }
    for(int i=0;i<=pointer;i++){
//        deal->appendCard(deck[i]);
        deck[i]->Move(deal, false, false);
        deck[i]->raise();// to top
        deck[i]->show();
    }
}
void Klondike::OnFiledClick(Card *c){
    if(c) PlayOff(c);
}

void Klondike::OnDealtClick(Card *c){
    if(c) PlayOff(c);
}

void Klondike::OnDealClick(Card * c){

    c->Move(waste,true, true);

}

void Klondike::OnEmptyDealClick()
{
    if(deal->Empty() && !waste->Empty()) {
        waste->Bottom()->Move(deal, false, false, true);
    }
}
