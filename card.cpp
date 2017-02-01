#include "pile.h"
#include "card.h"
QPoint Card::startDragPos;
QPoint Card::mouseDownOffset;
QPoint Card::popUpPos;
Card* Card::popUpCard;
QImage Card::faces[53];
bool Card::initialized = false;

Card::Card(int v, QWidget *parent):QLabel(parent){
    value = v;
}

Card::Card(pips p, suits s, QWidget *parent = 0):QLabel(parent){
    pip=p;
    suit = s;
    if(s == DIAMONDS || s == HEARTS ){
        color = RED;
    }else{
        color = BLACK;
    }
}

int Card:: StackSize(){
    int count=0;
    Card *card=this;
    do{
        count++;
        card=card->over;
    }while(card);
    return count;
}
void Card::mousePressEvent(QMouseEvent *ev){
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
    if(ev->button()) return;
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
}
void Card::mouseDoubleClickEvent(QMouseEvent *ev){
    if(pile)pile->mouseDoubleClickEvent(this);
    //if(!over)//try to play-off card;
    //Playoff();
}
void Card::Move(Pile *to, bool expose = true){

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
//
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
//
  //  game->Playoff(this);
}

void shuffle(Card* Deck[],int n){
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

