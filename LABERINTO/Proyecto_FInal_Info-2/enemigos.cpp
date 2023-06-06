#include "enemigos.h"

void Enemigo1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/brunaa.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF Enemigo1::boundingRect() const
{
    return QRectF(-20,-20,20,20);
}
Enemigo1::Enemigo1(){

}

void Enemigo2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/arik.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF Enemigo2::boundingRect() const
{
    return QRectF(-20,-20,20,40);
}
Enemigo2::Enemigo2(){

}

void Enemigo3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/ten hag.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF Enemigo3::boundingRect() const
{
    return QRectF(-20,-20,20,42);
}
Enemigo3::Enemigo3(){

}
