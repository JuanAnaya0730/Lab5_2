#include "obstaculo.h"

Obstaculo::Obstaculo(int pos_X, int pos_Y, int Ancho_, int Alto_)
{
    posX = pos_X;
    posY = pos_Y;
    Ancho = Ancho_;
    Alto = Alto_;
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(posX, posY, Ancho, Alto);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
}
