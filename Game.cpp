#include "Game.h"
#include "Health.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QApplication>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // Make the Scene 800x600 instead of Infinity by Infinity (Default).
    this->setWindowTitle("Town Savior");

    //Set the Background
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    // Make the Newly created Scene the scene to visualize (since Game is a QGraphicsView Widget, it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // Create the Player
    player = new Player();
    player->setPos(400,500);
    // Make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // Add the player to the scene
    scene->addItem(player);

    // Create the Score & Health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+30);
    scene->addItem(health);

    // Spawn Enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //Playing the Background Music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->play();
    show();

    connect( health, SIGNAL(dead()), this, SLOT(end()) );

}
void Game::end(){
    QApplication::quit();
}

