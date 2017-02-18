#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    //change the window's title to about
    setWindowTitle("help");

    //change the tab's title
    ui->tabWidget->setTabText(0, "Klondike");
    ui->tabWidget->setTabText(1, "Freecell");
    ui->tabWidget->setTabText(2, "Spider");
}

help::~help()
{
    delete ui;
}
