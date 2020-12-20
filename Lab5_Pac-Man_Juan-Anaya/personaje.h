#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>

class Personaje: public QObject, public QGraphicsItem
{
private:
    int posX;
    int posY;
    float filas, columnas;
    float ancho, alto;
    QGraphicsPixmapItem *cuerpo;
    QGraphicsRectItem *centro;
    QGraphicsRectItem *corteza;
    QTimer *timer;

public:
    //Personaje();
    Personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setX_Y(QList<int> direccion);

    int getPosX() const;
    void setPosX(int X_);

    int getPosY() const;
    void setPosY(int Y_);

    QGraphicsRectItem *getCentro() const;
    QGraphicsRectItem *getCorteza() const;
    QGraphicsPixmapItem *getCuerpo() const;
    void actualizarPosiciones();

public slots:
    void actulizarSprite();

};

#endif // PERSONAJE_H
