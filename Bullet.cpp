#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; // There's an External global object called game.

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // Draw Graphics
    setPixmap(QPixmap(":/images/bullet.png"));


    // Make a Timer to move() the Bullet
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // Start the Timer
    timer->start(50);
}

void Bullet::move(){
    // Get a list of the items that are Currently Colliding with this Bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // If one of the Colliding items is an Enemy, Destroy both the Bullet and the Enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            // Remove the Bullet and the Enemy from the Scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // Delete them from the Heap to Save Memory
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // If there was no Collision with an Enemy, Move the Bullet Forward
    setPos(x(),y()-10);
    // If the Bullet is Off the Screen, Destroy that Bullet
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
