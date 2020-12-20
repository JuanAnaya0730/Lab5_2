#include "moneda.h"

Moneda::Moneda(int pos_X, int pos_Y, int Ancho_, int Alto_)
{
    setPixmap(QPixmap(":/Imagenes/Moneda.png"));
    posX = pos_X;
    posY = pos_Y;
    Ancho = Ancho_;
    Alto = Alto_;
    QRectF(0,0,Ancho, Alto);
    this->setPos(posX, posY);
}
