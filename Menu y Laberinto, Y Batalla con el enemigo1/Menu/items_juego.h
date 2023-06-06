#ifndef ITEMS_JUEGO_H
#define ITEMS_JUEGO_H

#include <QGraphicsItem>
#include <QPainter>

class gatorade : public QGraphicsItem{
public:
    gatorade();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    int bonoATK = 50;
    int vy;
};

class botiquin : public QGraphicsItem{
public:
    botiquin();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void curar();
    int vy;
};

class chaleco : public QGraphicsItem{
public:
    chaleco();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    int vy;
};

class corazon : public QGraphicsItem{
public:
    corazon();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    int bonoVIDA = 80;
    int vy;
};

#endif // ITEMS_JUEGO_H
