#include "gameboard.h"
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

}

void gameboard::on_actionSpider_triggered()
{

}

void gameboard::on_actionFreeccell_triggered()
{

}
