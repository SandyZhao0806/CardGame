#include "pile.h"
#include "card.h"
#include "gameboard.h"
#include "cardmove.h"
#include <QStyleOption>
#include <QPainter>
#include <QStyle>


//extern gameboard *MainApp;
extern Game *game;
//extern QList<Pile *> piles;

// constructor
Pile::Pile(int x, int y, int dx, int dy, QWidget *parent, Game *game):
    QLabel(parent),delta(QPoint(dx,dy)),top(0),bottom(0),game(game)
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
    top=c->under;
    c->setParent(0);
    delete c;
    }

    int i =0 ;
    Rule *r = DragRule(i);
    while(r){
        delete r;
        DragRule(i++,NULL);
        r= DragRule(i);
    }

    for(i=0,r=DropRule(i);r;r=DropRule(++i)){
        delete r;
        DropRule(i,NULL);
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

void Pile::AcceptCards(Card *c, bool expose)
{
    Card * topMost;
    Card * temp = c;
    do
    {
        topMost = temp;
        topMost->Faceup(expose);//Important : This will set pixmap!
        temp->setPile(this);//update the card's pile
        temp = temp->Over();
    } while (temp);//temp will be NULL finally.

    if(top)
    {
        top->setOver(c);
        c->setUnder(top);
    }
    top = topMost;
    if(!bottom)
        bottom = c;
    c->AlignWithPile();
}

void Pile::ReleaseCards(Card *c, bool expose ){
    top = c->Under();
    if(top){//if top exist...
        //the new top should have no card on it.
        top->setOver(0);
        top->Faceup(expose);
    }
    if(bottom==c)
        bottom = 0;
    c->setUnder(0);

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

void Pile::AddDragRules(int n...){
    va_list lp;
    va_start(lp,n);
    int i = 0;
    while(i<n)
        DragRule(i++,va_arg(lp,Rule*));
    DragRule(i,NULL);
    va_end(lp);
}

bool Pile::CanBeDragged(Card *c){
    int i =0;
    bool ok =true;
    while(ok && DragRule(i)){
        ok = DragRule(i)->Enforce(this,c);
        i++;
    }

    return ok;
}

bool Pile::CanBeDropped(Card* c){
    int i =0;
    bool ok =true;
    while(ok && DropRule(i)){
        ok = DropRule(i)->Enforce(this,c);
        i++;
    }
    return ok;
}

void Pile::FindClosestDrop(Card *c)
{
    const int NUM = 3;
    QPoint drop = c->pos();
    Pile *closest[NUM] = {NULL, NULL, NULL};
    int distance[NUM] = {100, 200, 300};//use smaller distances.
    for (int i = 0; i<game->piles.count(); i++)
    {
        Pile *p = game->piles[i];
        if (p == c->pile) continue;
        QPoint diff = drop - (p->top?p->top->pos():p->pos());
        int dist = diff.manhattanLength();
        for (int j = 0; j < NUM; j++)
        {
            if (dist < distance[j])
            {
                std::swap(dist, distance[j]);
                std::swap(p, closest[j]);
            }
        }
    }
    for (int i = 0; i < NUM; i++)
    {
        if (closest[i] && closest[i]->CanBeDropped(c))
        {
            //use move to handle the exchange of cards.
            c->Move(closest[i],true,true,true);
            return;
        }
    }
    QPoint p = c->under?(c->under->pos()+c->pile->Delta()/(c->under->faceup?1:2)):c->pile->pos();
    c->AdjustPositions(p, c->pile->delta); // put them back if no move
}

void Pile::mouseReleaseEvent(QMouseEvent * ev)
{
    game->OnEmptyDealClick();
}
