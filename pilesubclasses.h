#ifndef PILE_SUBCLASSES_H
#define PILE_SUBCLASSES_H
class Pile;
// Inheriting classes that differ in rules
class PileStock:public Pile
{   public:
    PileStock(int x, int y, int dx, int dy, QWidget *parent);
    //TODO
};
class PileFoundation:public Pile
{
    public:
    PileFoundation(int x, int y, int dx, int dy, QWidget *parent);
    //TODO
};
class PileTableau:public Pile
{
    public:
    PileTableau(int x, int y, int dx, int dy, QWidget *parent);
    //TODO
};
//    class PileFreeCell:public Pile
//    {
//        //TODO
//    };
class PileWaste:public Pile
{
    public:
    PileWaste(int x, int y, int dx, int dy, QWidget *parent);
    //TODO
};


#endif
