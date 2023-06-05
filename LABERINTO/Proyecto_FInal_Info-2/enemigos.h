#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QGraphicsItem>
#include <QPainter>

class Enemigo1:public QGraphicsItem{
public:
    Enemigo1();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void combate();
    int vida = 100;
    int ataque = 50;

};

class Enemigo2:public QGraphicsItem{
public:
    Enemigo2();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void combate();
    int vida = 200;
    int ataque = 100;
};

class Enemigo3:public QGraphicsItem{
public:
    Enemigo3();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void combate();
    int vida = 300;
    int ataque = 150;
};

#endif // ENEMIGOS_H
