#include "gameboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameboard w;
    w.show();

    return a.exec();
}
