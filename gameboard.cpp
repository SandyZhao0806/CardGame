#include "gameboard.h"
#include "game.h"
#include "klondike.h"
#include "ui_gameboard.h"

gameboard::gameboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameboard)
{
    ui->setupUi(this);
}

gameboard::~gameboard()
{
    delete ui;
}

void gameboard::on_actionKlondike_triggered()
{
   Game * g = new Klondike(ui->centralWidget);
   g->ReDeal(REPEAT);
}

void gameboard::on_actionSpider_triggered()
{

}

void gameboard::on_actionFreeccell_triggered()
{

}
