#include "rule.h"
#include "pile.h"
#include "card.h"
#include "gameboard.h"


extern gameboard *MainApp;
extern Game *game;

bool RuleBaseNone::
// WARNING: Card * c is the card which the user is grabbing.
// Not the very top one!
Enforce(Pile *,Card *)
{
    return false;
}
//--------------------------------------
bool RuleBaseAce::
Enforce(Pile *p,Card *c)
{
    return !p->Empty() || c->Pip()==ACE;
}
//--------------------------------------
bool RuleBaseKing::
Enforce(Pile *p,Card *c)
{
return !p->Empty() || c->Pip()==KING;
}
//--------------------------------------
bool RuleNoStack::
Enforce(Pile *p,Card *c) {
    int cs = c->StackSize();
    int fm = game->FreeMoves();
    fm>>= p->Empty()?1:0;
    return cs <=fm;
}
//--------------------------------------
bool RuleStackSameSuit::
Enforce(Pile *p,Card *c) {
    Card *temp = p->Top();
    if(!temp) return true;//empty pile can match any suit.
    bool ok = c->Suit()==temp->Suit();
        while (ok && temp->Under())
        {
            ok = temp->Suit() == temp->Under()->Suit();
            temp = temp->Under();
        }
        return ok;
}
//--------------------------------------
bool RuleStackAlternateColor::
Enforce(Pile *p,Card *c)
{
    if(!p->Top())
        return true;// empty pile = match any
    bool ok = p->Top()->Color()!=c->Color();
    Card *temp = p->Top();
    while(ok&&temp->Over()){
        ok=temp->Color()!=temp->Over()->Color();
        temp=temp->Over();
    }
    return ok;
}
//--------------------------------------
bool RuleStackMinusOne::
Enforce(Pile *p,Card *c) {
    return p->Empty() || p->Top()->Pip() - c->Pip() == 1;
}
//--------------------------------------
bool RuleStackPlusOne::
Enforce(Pile *p,Card *c) {
    return p->Empty() || c->Pip() - p->Top()->Pip() == 1;
}
//--------------------------------------
bool RuleStackAny::
Enforce(Pile *p,Card *c) {
    return true;
}
//--------------------------------------
bool RuleStackOneAtATime::
Enforce(Pile *p,Card *c) {
    //if c has card on its top, return false
    return !c->Over();
}
//--------------------------------------
bool RuleStack13::
Enforce(Pile *p,Card *c) {
    Card* temp = c;
    bool ok = true;
    int val = c->Pip();
    suits s = c->Suit();
    while ( ok &&
            (ok =(temp->Pip() == val &&
                  temp->Suit() == s) )
            && val < KING )
        val = (val + 1);
        temp = temp->Over();
        ok = temp;
    return ok;
}
//--------------------------------------
bool RuleStackLengthLimited::
Enforce(Pile *p,Card *c) {
    int cs = c->StackSize();
    int fm = game->FreeMoves();
    fm >>= p->Empty()?1:0;
    return cs <=fm;
}
//--------------------------------------
bool RuleMoveSameSuit::
Enforce(Pile *p,Card *c) {
    bool ok = true;
    while(ok && c->Over()){
        ok = c->Suit() == c->Over()->Suit();
        c = c->Over();
    }
    return ok;

}
//--------------------------------------
bool RuleMoveAltColor::
Enforce(Pile *p,Card *c) {
    bool ok = true;
    while(ok && c->Over()){
        ok = c->Color() !=c->Over()->Color();
        c = c->Over();
    }
    return ok;
}
//--------------------------------------
bool RuleMoveSeqDecreasing::
Enforce(Pile *p,Card *c) {
    bool ok = true;
    while(ok && c->Over()){
        ok = 1 == c->Over()->Pip() - c->Pip();
        c = c->Over();
    }
    return ok;
}
//--------------------------------------
bool RuleMoveSeqIncreasing::
Enforce(Pile *p,Card *c) {
    bool ok = true;
        while (ok && c->Over())
        {
            ok = 1 == c->Pip() - c->Over()->Pip();
            c = c->Over();
        }
        return ok;
}
//--------------------------------------
bool RuleMoveLengthLimited::
Enforce(Pile *p,Card *c) {
    return c->StackSize() <= game->FreeMoves();
}
//--------------------------------------
bool RuleMoveNone::
Enforce(Pile *p,Card *c) {
    return false;
}
//--------------------------------------
bool RuleForFreeCell::
     Enforce(Pile *p,Card *c){
     if(p->Empty()) return true;
}
