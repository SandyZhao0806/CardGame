#include "gameboard.h"
#include <QTime>
#include <QtGlobal>
#include "game.h"
#include "klondike.h"
#include "spider.h"
#include "freecell.h"
#include "ui_gameboard.h"
#include "card.h"

gameboard::gameboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameboard)
{
    ui->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

gameboard::~gameboard()
{
    delete ui;
}

void gameboard::on_actionKlondike_triggered()
{

    // initialize
   Card::Initialize();
   if(g)
       delete g;//Temp solution : (should have a game end functions)
   g = new Klondike(ui->centralWidget);
   setWindowTitle(g->GameName());
   g->ReDeal(REPEAT);
}

void gameboard::on_actionSpider_triggered()
{
    // initialize
   Card::Initialize();
   if(g)
       delete g;//Temp solution : (should have a game end functions)
   g = new Spider(ui->centralWidget);
   setWindowTitle(g->GameName());
   g->ReDeal(REPEAT);

}

void gameboard::on_actionFreeccell_triggered()
{
    // initialize
   Card::Initialize();
   if(g)
       delete g;//Temp solution : (should have a game end functions)
   g = new FreeCell(ui->centralWidget);
   setWindowTitle(g->GameName());
   g->ReDeal(REPEAT);
}

void gameboard::on_actionRedeal_triggered()
{
    if(!g) return;
    g->ReDeal();

}
