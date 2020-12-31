#ifndef MAIN_H
#define MAIN_H
#include <QGraphicsScene>
#include <QGraphicsView>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
};

#endif // MAIN_H
