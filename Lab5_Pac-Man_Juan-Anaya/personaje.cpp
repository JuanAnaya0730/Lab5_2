#include "personaje.h"

Personaje::Personaje()
{
    posX=212;
    posY=460;

    corteza = new QGraphicsRectItem();
    centro = new QGraphicsRectItem();
    cuerpo = new QGraphicsPixmapItem();

    corteza->setRect(0,0,30,30);
    centro->setRect(0,0,8,8);
    cuerpo->setPixmap(QPixmap(":/Imagenes/Pacman.png"));

    this->actualizarPosiciones();

    timer = new QTimer();
    filas = 0;
    columnas = 0;

    //Dimensiones de cada imagen
    ancho = 80;
    alto = 100;

    timer->start(50); //Aqui el frame
    connect(timer, &QTimer::timeout, this, &Personaje::actulizarSprite);
}

QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);

}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, cuerpo->pixmap(), columnas, 0, ancho, alto);
}

void Personaje::setX_Y(QList<int> direccion)
{
    posX = corteza->x() + direccion.at(0);
    posY = corteza->y() + direccion.at(1);
    this->actualizarPosiciones();
}

void Personaje::actualizarPosiciones()
{
    corteza->setPos(posX, posY);
    centro->setPos(posX+10, posY+10);
    cuerpo->setPos(posX-1, posY-1);
}

void Personaje::actulizarSprite()
{
    columnas += ancho;
    if(columnas >= 96){
        columnas = 0;
    }
    cuerpo->update(-ancho/2, -alto/2, ancho, alto);
}

QGraphicsRectItem *Personaje::getCentro() const
{
    return centro;
}

QGraphicsRectItem *Personaje::getCorteza() const
{
    return corteza;
}

QGraphicsPixmapItem *Personaje::getCuerpo() const
{
    return cuerpo;
}

int Personaje::getPosX() const{
    return posX;
}

void Personaje::setPosX(int X_){
    posX = X_;
    corteza->setPos(posX, posY);
}

int Personaje::getPosY() const{
    return posY;
}

void Personaje::setPosY(int Y_){
    posY = Y_;
    corteza->setPos(posX, posY);
}
