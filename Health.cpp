#include "Health.h"
#include "Score.h"
#include <QFont>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QPushButton>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize the Score to 0
    health = 5;

    // Draw the Text on the Scene
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    if(health == 0){
        emit dead();
    }
}

int Health::close(){
    close();
    return health;
}

