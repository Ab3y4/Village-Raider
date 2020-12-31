#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QPushButton>

class Health: public QGraphicsTextItem{
    Q_OBJECT
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int close();
    void gameOver();
signals:
    void dead();

private:
    int health;
};

#endif // HEALTH_H
