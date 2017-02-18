#include "spider.h"
#include "pile.h"
#include "pilesubclasses.h"
#include "card.h"
#include "cardmove.h"

Spider::Spider(QWidget *par):Game(par)
{

}

Spider::~Spider(){

}

void Spider::CreatePile(){
    //create piles
    const int span = 30;
    for(int i = 0 ; i < 10; i++){
        tableau[i] = new PileTableau(30+(span+71)*i,30,71,96,parent,this);
    }
    tableau[0]->AddDragRules(2, new RuleMoveSameSuit(), new RuleMoveSeqIncreasing());
    tableau[0]->AddDropRules(1, new RuleStackMinusOne());
    for(int i = 0 ; i < 8; i++){
        foundation[i] = new PileFoundation(30+(span+71)*i,500,71,96,parent,this);
    }
    foundation[0]->AddDragRules(1, new RuleStackOneAtATime());
    foundation[0]->AddDropRules(4,new RuleBaseAce(),new RuleMoveSeqDecreasing(), new RuleStackSameSuit(), new RuleStackPlusOne());
    deal = new PileStock(950,500,71,96,parent,this);
    deal->AddDragRules(1, new RuleBaseNone());
    deal->AddDropRules(1,new RuleBaseNone());
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
            deck[pointer]->Move(tableau[i], (j==5&&i<4||j==4&&i>=4)? true : false);// expose the card on top
            deck[pointer]->raise();// to top
            deck[pointer--]->show();
        }
    }
    for(int i=0;i<=pointer;i++){
//        deal->appendCard(deck[i]);
        deck[i]->Move(deal, false);
        deck[i]->raise();// to top
        deck[i]->show();
    }
}

void Spider::OnDealClick(Card * c){
    int i = 0;// Use i to record how many times the loop is executed
    for(i = 0 ; i < 10; i++){
        if(deal->Top())
        deal->Top()->Move(tableau[i],true, true);
        else break;
    }
    // After dealing, Insert an "n" CardMove to the undostack
    // So this dealing process will be undo together.
    new CardMove(i);//i should be the times of the loop above
}

void Spider::OnFiledClick(Card *c){
    if(c) PlayOff(c);
}

void Spider::OnDealtClick(Card *c){
    if(c) PlayOff(c);
}
