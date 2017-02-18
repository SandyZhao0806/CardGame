#ifndef PILE_SUBCLASSES_H
#define PILE_SUBCLASSES_H
#include "rule.h"
class Pile;
class Game;
// Inheriting classes that differ in rules
class PileStock:public Pile
{   public:
    PileStock(int x, int y, int dx, int dy, QWidget *parent, Game *game);
    void onClickEvent(Card *);
    static Rule * dragRules[DRAGLAST];
    static Rule * dropRules[DROPLAST];
    void DragRule(int i, Rule *r);
    void DropRule(int i, Rule *r);
    Rule * DragRule(int i);
    Rule *DropRule(int i);
    pileType Type();
    //TODO
};
class PileFoundation:public Pile
{
    public:
    PileFoundation(int x, int y, int dx, int dy, QWidget *parent, Game *game);
    void onClickEvent(Card *){}
    static Rule * dragRules[DRAGLAST];
    static Rule * dropRules[DROPLAST];
    void DragRule(int i, Rule *r);
    void DropRule(int i, Rule *r);
    Rule * DragRule(int i);
    Rule *DropRule(int i);
    pileType Type();
    //TODO
};
class PileTableau:public Pile
{
    public:
    PileTableau(int x, int y, int dx, int dy, QWidget *parent, Game *game);
    void onClickEvent(Card *);
    static Rule * dragRules[DRAGLAST];
    static Rule * dropRules[DROPLAST];
    void DragRule(int i, Rule *r);
    void DropRule(int i, Rule *r);
    Rule * DragRule(int i);
    Rule *DropRule(int i);
    pileType Type();
    //TODO
};
class PileFreeCell:public Pile
{
    public:
    PileFreeCell(int x, int y, int dx, int dy, QWidget *parent, Game *game);
    void onClickEvent(Card *);
    static Rule * dragRules[DRAGLAST];
    static Rule * dropRules[DROPLAST];
    void DragRule(int i, Rule *r);
    void DropRule(int i, Rule *r);
    Rule * DragRule(int i);
    Rule *DropRule(int i);
    pileType Type();
    //TODO
};
class PileWaste:public Pile
{
    public:
    PileWaste(int x, int y, int dx, int dy, QWidget *parent, Game *game);
    void onClickEvent(Card *);
    static Rule * dragRules[DRAGLAST];
    static Rule * dropRules[DROPLAST];
    void DragRule(int i, Rule *r);
    void DropRule(int i, Rule *r);
    Rule * DragRule(int i);
    Rule *DropRule(int i);
    pileType Type();
    //TODO
};


#endif
