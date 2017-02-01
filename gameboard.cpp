#include "gameboard.h"
#include <QTime>
#include <QtGlobal>
#include "game.h"
#include "klondike.h"
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
   g->ReDeal(REPEAT);
}

void gameboard::on_actionSpider_triggered()
{

}

void gameboard::on_actionFreeccell_triggered()
{

}
