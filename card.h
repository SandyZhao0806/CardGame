#ifndef CARD_H
#define CARD_H
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPoint>
#include "gameboard.h"

class Game;

extern gameboard *gb;
extern Game * game;

enum cardColors{BLACK, RED};
enum pips{ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,SUIT_SIZE};
enum suits{CLUBS,DIAMONDS,HEARTS,SPADES};
class Pile; //forward declaration

class Card: public QLabel
{

private:
    static QImage faces[53];
    static bool initialized;
    int value;
    Card *under;
    Card *over;
    Pile *pile;

    cardColors color;
    pips pip;
    suits suit;
    bool faceup;
    bool moving;
    bool okToDrag;

    bool hasMouseDown;
    static QPoint mouseDownOffset; // Distance to add to mouse pos to move
    static QPoint startDragPos;
    static Qt::MouseButtons buttonDown;
    static QPoint popUpPos;
    static Card *popUpCard;

public:
    Card(int v, QWidget *parent = 0);
    Card(pips p, suits s, QWidget *parent);
    suits Suit(){return suit;}
    pips Pip(){return pip;}
    cardColors Color(){return color;}
    Pile *Pilep(){return pile;}
    void setPile(Pile *pile){this->pile = pile;}
    Card *Over(){return over;}
    void setOver(Card *over){this->over = over;}
    Card *Under(){return under;}
    void setUnder(Card *under){this->under = under;}
    int StackSize();
    bool Faceup(){return faceup;}
    void Faceup(bool f);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void Move(Pile *to, bool expose = true, bool record = true);
    void Move(Pile *to, bool expseTop, bool expose, bool record);
    Card *AdjustPositions(QPoint newPos, QPoint delta);
    void AlignWithPile();
    void Animate(QPoint newPos);
    static void Initialize(); // init static variable
    void Flip();  //filp the card
    QSize sizeHint() const;
    void Playoff();
    friend class Pile;

};

void Shuffle(Card *Deck[], int n);

#endif // CARD_H
