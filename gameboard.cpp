#include "gameboard.h"
#include <QTime>
#include <QtGlobal>
#include "game.h"
#include"cardmove.h"
#include "klondike.h"
#include "spider.h"
#include "freecell.h"
#include "ui_gameboard.h"
#include "card.h"
#include "rule.h"
#include "help.h"
#include "about.h"

Game *game = 0;

gameboard::gameboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameboard)
{
    ui->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    menuBar()->setNativeMenuBar(false);
    //reference: http://stackoverflow.com/questions/25261760/menubar-not-showing-for-simple-qmainwindow- code-qt-creator-mac-os

}

gameboard::~gameboard()
{
    delete ui;
}

void gameboard::on_actionKlondike_triggered()
{

    // initialize
   Card::Initialize();
   if(game)
       delete game;//Temp solution : (should have a game end functions)
   game = new Klondike(ui->centralWidget);
   setWindowTitle(game->GameName());
   game->ReDeal(REPEAT);
//   CardMove::Clear();
}

void gameboard::on_actionSpider_triggered()
{
    // initialize
   Card::Initialize();
   if(game)
       delete game;//Temp solution : (should have a game end functions)
   game = new Spider(ui->centralWidget);
   setWindowTitle(game->GameName());
   game->ReDeal(REPEAT);

}

void gameboard::on_actionFreeccell_triggered()
{
    // initialize
   Card::Initialize();
   if(game)
       delete game;//Temp solution : (should have a game end functions)
   game = new FreeCell(ui->centralWidget);
   setWindowTitle(game->GameName());
   game->ReDeal(REPEAT);
}

void gameboard::on_actionRedeal_triggered()
{
    if(!game) return;
    game->ReDeal();

}

void gameboard::on_actionUndo_triggered()
{
    CardMove::UndoMove();
}


void gameboard::on_actionAbout_3_triggered()
{

        about *a = new about(gb);
        a->exec();//use modal dialog.

}

void gameboard::on_actionHelp_3_triggered()
{
    help *h = new help(this);
    h->exec();
}

void gameboard::on_actionPlay_Off_triggered()
{
    if(!game) return;
    game->PlayOffAll();
}
