#include "gameboard.h"
#include "card.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameboard w;
    gb = &w;
    w.show();

    return a.exec();
}
