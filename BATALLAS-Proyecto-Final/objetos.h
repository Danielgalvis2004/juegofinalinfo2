#ifndef OBJETOS_H
#define OBJETOS_H

#include <QGraphicsItem>
#include <QPainter>

class jugador1 : public QGraphicsItem{
public:
    jugador1();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class balon : public QGraphicsItem{
public:
    balon();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};


class Enemigo1 : public QGraphicsItem{
public:
    Enemigo1();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // OBJETOS_H
