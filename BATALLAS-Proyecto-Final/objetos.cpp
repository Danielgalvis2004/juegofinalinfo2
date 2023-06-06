#include "objetos.h"

jugador1::jugador1(){

}
void jugador1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/BATALLA/nuevo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF jugador1::boundingRect() const{
    return QRectF(-10,-10,120,280);
}

balon::balon(){

}
void balon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/BATALLA/mapCIUDSd.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF balon::boundingRect() const{
    return QRectF(-10,-10,50,50);
}

Enemigo1::Enemigo1(){

}
void Enemigo1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/BATALLA/nuevo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF Enemigo1::boundingRect() const{
    return QRectF(-10,-10,120,280);
}
