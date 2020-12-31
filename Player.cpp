#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet_sound.wav"));

    // Set the Graphics
    setPixmap(QPixmap(":/images/tank.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // Move the Player Left and Right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }

    // Shoot with the Spacebar
    else if (event->key() == Qt::Key_Space){

        // Create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+16,y());
        scene()->addItem(bullet);

        // Play the Bullet Sound
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        bulletsound->play();
    }
}

void Player::spawn(){
    // Create an Enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy); }
