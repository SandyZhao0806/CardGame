#include "pile.h"
#include "card.h"
#include "gameboard.h"
#include "cardmove.h"
#include <QStyleOption>
#include <QPainter>
#include <QStyle>


extern gameboard *MainApp;
extern Game *game;
extern QList<Pile *> piles;

// static member data allocation
//Rule *PileStock::dragRules[DRAGLAST];
//Rule *PileStock::dropRules[DROPLAST];

//Rule *PileFoundation::dragRules[DRAGLAST];
//Rule *PileFoundation::dropRules[DROPLAST];

//Rule *PileTableau::dragRules[DRAGLAST];
//Rule *PileTableau::dropRules[DROPLAST];

//Rule *PileFreeCell::dragRules[DRAGLAST];
//Rule *PileFreeCell::dropRules[DROPLAST];


//Rule *PileWaste::dragRules[DRAGLAST];

// constructor
Pile::Pile(int x, int y, int dx, int dy, QWidget *parent):
    QLabel(parent),delta(QPoint(dx,dy)),top(0),bottom(0)
{
        setStyleSheet("border: 2px dotted grey;");
        setParent(parent);
        setFrameShape(Box);
        resize(dx,dy);
        move(x,y);
        setLineWidth(2);
        show();
    //TODO
}
Pile::~Pile()
{
    while(top){
    Card *c = top;
    top=c->over;
    c->setParent(0);
    delete c;
    }

    //TODO
}

void Pile::paintEvent(QPaintEvent *pe)

{

    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(
    QStyle::PE_Widget, &o, &p, this);

}

void Pile::AcceptCards(Card *c, bool expose, bool record)
{
    Card * topMost;
    Card * temp = c;
    do
    {
        topMost = temp;
        topMost->Faceup(expose);//Important : This will set pixmap!
        temp = temp->Over();
    }while (temp);//temp will be NULL finally.

    if(top)
    {
        top->setOver(c);
        c->setUnder(top);
    }
    top = topMost;
    if(!bottom)
        bottom = top;
}

void Pile::AddDropRules(int n...)
{
    va_list lp;
    va_start(lp,n);
    int i = 0;
    while(i<n)
        DropRule(i++,va_arg(lp,Rule*));
    DropRule(i,NULL);
    va_end(lp);
}
