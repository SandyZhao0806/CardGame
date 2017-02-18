#include "pile.h"
#include "card.h"
#include "rule.h"
#include "game.h"
#include "cardmove.h"
QPoint Card::startDragPos;
QPoint Card::mouseDownOffset;
QPoint Card::popUpPos;
Card* Card::popUpCard;
QImage Card::faces[53];

gameboard *gb=0;

bool Card::initialized = false;

Card::Card(int v, QWidget *parent)
    :QLabel(parent), under(0), over(0), pile(0){
    value = v;
    resize(71, 96);
}

Card::Card(pips p, suits s, QWidget *parent = 0)
    :QLabel(parent), under(0), over(0), pile(0){
    pip=p;
    suit = s;
    // Calculate value!
    value = s * SUIT_SIZE + p;
    if(s == DIAMONDS || s == HEARTS ){
        color = RED;
    }else{
        color = BLACK;
    }
    resize(71, 96);
}

int Card:: StackSize(){
    int count=0;
    Card *card=this;
    do{
        count++;
        card=card->under;//for me I use "under" to refer the card under "this"
    }while(card);
    return count;
}

void Card::mousePressEvent(QMouseEvent *ev){
    moving = false;//initialize when mouse button is down.
    switch(ev->button()){
    case Qt::LeftButton:
        startDragPos=pos();
        mouseDownOffset=pos()-ev->globalPos();
        okToDrag=faceup && pile->CanBeDragged(this);
        break;
     case Qt::RightButton:
        popUpPos=pos();
        popUpCard=this;
        move(pos()+QPoint(0,-20));
        break;
     default: ;
    }
}
void Card::mouseMoveEvent(QMouseEvent *ev){
    QPoint point =ev->globalPos()+mouseDownOffset;
    QPoint moved =point-pos();
    if(okToDrag && moved.manhattanLength()>4)
        // the mouse has moved more than 4 pixel since the oldposition
        moving=true;
    if(moving)
        AdjustPositions(point,pile?pile->Delta():QPoint(0,10));
}
void Card::mouseReleaseEvent(QMouseEvent *ev){
    //if(ev->button()) return;
    if(popUpCard){
        popUpCard->move(popUpPos);//restore card position
        popUpCard=NULL;
        return;
    }
    if(moving && pile)
        pile ->FindClosestDrop(this);
    else
        if(pile){
            QPoint point =ev->globalPos()+mouseDownOffset;
            QPoint moved =point-pos();
            if(moved.manhattanLength()<=4)
                pile->onClickEvent(this);
        }
    moving=false;
    okToDrag=false;
    game->CheckWin();

}
void Card::mouseDoubleClickEvent(QMouseEvent *ev){
    if(pile)pile->mouseDoubleClickEvent(this);
//    if(!over)//try to play-off card;
//    Playoff();
}
void Card::Move(Pile *to, bool expose, bool record){
  Move(to, false, expose, record);
}

void Card::Move(Pile *to, bool exposeTop, bool expose, bool record){
    Pile * from;
    if(from = Pilep()) {
        // Create a record of the card move before it is moved to another pile
        if(record)
            new CardMove(this,from,to);
        //This breaks the link of the orignial pile(cards are double-direction linked list)
        Pilep()->ReleaseCards(this, exposeTop);
    }
    to->AcceptCards(this, expose);

}


Card* Card::AdjustPositions(QPoint newPos, QPoint delta){
    Card *c =this;
    Card *top;
    do{
        c->move(newPos);
        c->raise();
        c->show();
        newPos += (delta/(c-faceup?1:2));
        top =c;
        c->pile=pile;
        c=c->over;
    }while(c);
    return top;
}
void Card::AlignWithPile(){
    //if pile is empty, just put the card right on the pile.
    //TODO: HANDLE EACH CARD ALL THE WAY TO THE TOP WITH THE LOGIC BELOW

    Card *p = this;
    do{
        Card *c = p->Under();
        if(!c)
            p->move(pile->x(), pile->y());
        else if(!c->Faceup()){
             p->move(c->x()+pile->Delta().x()/2,
            c->y()+pile->Delta().y()/2);
        }
        else{
            p->move(c->x()+pile->Delta().x(),
           c->y()+pile->Delta().y());
        }

        p->raise();
        p = p->Over();

    }while(p);
}
void Card::Animate(QPoint newPos){
//
}

void Card::Initialize()
{
    if(initialized) return;
    initialized = true;
    char suit[] = {'c','d','h','s'};
    char pip[] = {'1','2','3','4','5','6','7','8','9','a','b','c','d'};
    QString fname =":/cards/c1.bmp";
    int n = 0;
    for(int s = CLUBS; s <= SPADES; ++s)
    {
        fname[8]=suit[s];
        for(int p=ACE;p<=KING;++p){
            fname[9]=pip[p];
            faces[n++]=QImage(fname);
        }
        // TODO
    }
    faces[n] =QImage(":/cards/zCardBack.bmp");
}

void Card::Flip(){
    Faceup(!faceup);
}
void Card::Faceup(bool f){
    faceup =f;
    setPixmap(QPixmap::fromImage(faces[faceup?value:52]));
}
QSize Card::sizeHint() const{
//
}
void Card::Playoff(){

    game->PlayOff(this);
}

void Shuffle(Card* Deck[],int n){
    Card* temp;
    int k;
    while(n>0){
        k=(uint)qrand()%n--;
        temp = Deck[k];
        Deck[k]=Deck[n];
        Deck[n]=temp;
        temp->raise();
    }
}

