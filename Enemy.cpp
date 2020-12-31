#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Set Random X Positions
    int random_number = rand() % 700;
    setPos(random_number,0);

    // Draw the Graphics
    setPixmap(QPixmap(":/images/bomb.png"));


    // Make a Timer to move() the Enemy
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // Start the Timer
    timer->start(50);
}

void Enemy::move(){
    // Move the Enemy Down
    setPos(x(),y()+5);

    // Destroy the Enemies when they go out of the Screen
    if (pos().y() > 600){
        //Decrease the Health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
