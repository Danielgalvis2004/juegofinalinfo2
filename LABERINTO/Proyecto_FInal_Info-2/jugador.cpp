#include "jugador.h"

jugador::jugador(){
    vy = 7;
}
void jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/nibi.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF jugador::boundingRect() const{
    return QRectF(-10,-10,20,20);
}
