#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsItem>
#include <QPainter>

class jugador : public QGraphicsItem{
public:
    jugador();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    int vy;
};

#endif // JUGADOR_H
