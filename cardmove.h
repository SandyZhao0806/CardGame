#ifndef CARDMOVE_H
#define CARDMOVE_H
#include <QStack>

class Pile;
class Card;
class CardMove
{
    Card *card;
    Pile *from;
    Pile *to;
    int count:16;
    bool wasFaceUp:1;// Whether this card was facing up
    bool wasUnderFaceUp:1;// Whether the card under this card(previously) was Facing up?
    static QStack<CardMove*> undostack;
public:
    CardMove();
    CardMove(Card *c, Pile *fr, Pile *t);
    //This constructor create an empty CardMove object but contains an "n" which
    //indicates that the following n of CardMoves will be done together.
    CardMove(int n);
    static void UndoMove();
    static void Clear();
};

#endif // CARDMOVE_H
