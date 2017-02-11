#include "rule.h"
#include "pile.h"
#include "card.h"
#include "gameboard.h"


extern gameboard *MainApp;
extern Game *game;

bool RuleBaseNone::
Enforce(Pile *,Card *)
{

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
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStackSameSuit::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStackAlternateColor::
Enforce(Pile *p,Card *c)
{
    if(p->Bottom()->Color() != c->Color())
        return true;
    return false;
//    bool ok =true;
//    while(ok&&c->Over()){
//        ok=c->Color()!=c->Over()->Color();
//        c=c->Over();
//    }
//    return ok;
}
//--------------------------------------
bool RuleStackMinusOne::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStackPlusOne::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStackAny::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStackOneAtATime::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStack13::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleStackLengthLimited::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleMoveSameSuit::
Enforce(Pile *p,Card *c) {
//    bool ok = true;
//    if(ok = c->Suit()==p->Bottom()->Suit())
//        p->Bottom()->Under() = c

}
//--------------------------------------
bool RuleMoveAltColor::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleMoveSeqDecreasing::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleMoveSeqIncreasing::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleMoveLengthLimited::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
bool RuleMoveNone::
Enforce(Pile *p,Card *c) {}
//--------------------------------------
