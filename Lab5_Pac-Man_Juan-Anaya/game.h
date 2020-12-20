#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsRectItem>
#include "personaje.h"
#include "nivel.h"
#include "obstaculo.h"

class Game: public QGraphicsView
{
private:
    QGraphicsScene *scene;
    Nivel nivel1;
    string direccion;
    string fdireccion;
    Personaje *Pacman;
    Personaje *cPacman;
    QTimer *tPacman;

public:
    Game();
    void keyPressEvent(QKeyEvent *event);
    bool colisionaconunitem(void);
    QList<int> mover(string d="");

public slots:
    void moverPersonaje(void);

};

#endif // GAME_H
