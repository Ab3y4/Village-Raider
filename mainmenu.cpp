#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "ui_howtoplay.h"
#include "howtoplay.h"
#include <QApplication>
#include "Game.h"
#include <QGraphicsScene>

Game * game;

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)

{
    ui->setupUi(this);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_btnExit_clicked()
{
    close();
}

void MainMenu::on_btnStart_clicked()
{
    //Starting the Game
    game = new Game();
    game->show();
}

void MainMenu::on_btnHowTo_clicked()
{
    // Opens the 'How to Play?' window
    HowToPlay *htp = new HowToPlay;
    htp->show();
    hide();
}
