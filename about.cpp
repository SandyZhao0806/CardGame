#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    //change the window's title to about
    setWindowTitle("about");
}

about::~about()
{
    delete ui;
}
