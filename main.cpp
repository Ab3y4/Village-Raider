#include <QApplication>
#include "Game.h"
#include "mainmenu.h"
#include <QGraphicsScene>

MainMenu * game2;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //Opening the Main Menu Window
    game2 = new MainMenu();
    game2->show();

    return a.exec();
}
