#ifndef MONEDA_H
#define MONEDA_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPainter>

class Moneda: public QGraphicsPixmapItem
{
private:
    int posX;
    int posY;
    int Ancho;
    int Alto;

public:
    Moneda(int pos_X, int pos_Y, int Ancho_, int Alto_);
};

#endif // MONEDA_H
