#include "items_juego.h"

void gatorade::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::green);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/GATO.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF gatorade::boundingRect() const
{
    return QRectF(-20,-20,18,18);
}
gatorade::gatorade(){
    vy=7;
}

void botiquin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::blue);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/bot.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF botiquin::boundingRect() const
{
    return QRectF(-20,-20,18,18);
}
botiquin::botiquin(){
    vy=7;
}

void chaleco::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::gray);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/CHALE.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF chaleco::boundingRect() const
{
    return QRectF(-20,-20,18,18);
}
chaleco::chaleco(){
    vy=7;
}

void corazon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/IMAGENES/CORA.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
QRectF corazon::boundingRect() const
{
    return QRectF(-20,-20,18,18);
}
corazon::corazon(){
    vy=7;
}
