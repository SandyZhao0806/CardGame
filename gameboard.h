#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>

namespace Ui {
class gameboard;
}

class gameboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameboard(QWidget *parent = 0);
    ~gameboard();

private slots:
    void on_actionKlondike_triggered();

    void on_actionSpider_triggered();

    void on_actionFreeccell_triggered();

    void on_actionRedeal_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_3_triggered();

    void on_actionHelp_3_triggered();

    void on_actionPlay_Off_triggered();

private:
    Ui::gameboard *ui;
};

#endif // GAMEBOARD_H
