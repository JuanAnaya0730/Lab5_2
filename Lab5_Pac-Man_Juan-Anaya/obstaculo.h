#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsItem>
#include <QPainter>

class Obstaculo: public QGraphicsItem
{
protected:
    int posX;
    int posY;
    int Ancho;
    int Alto;

public:
    Obstaculo(int pos_X, int pos_Y, int Ancho_, int Alto_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // OBSTACULO_H
