#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "enemigos.h"
#include "items_juego.h"
#include "mi_esfera.h"
#include "jugador.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();
    void aumentarPuntos();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    QGraphicsRectItem* bordeI;
    QGraphicsRectItem* bordeD;
    QGraphicsRectItem* bordeS;
    QGraphicsRectItem* bordeIn;
    QGraphicsRectItem* borde1;
    QGraphicsRectItem* borde2;
    QGraphicsRectItem* borde3;
    QGraphicsRectItem* borde4;
    QGraphicsRectItem* borde5;
    QGraphicsRectItem* borde6;
    jugador* pac;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    miesfera* bola0;
    miesfera* bola00;
    miesfera* bola000;
    miesfera* bola0000;
    miesfera* bola00000;

    gatorade* bola1;
    chaleco* bola3;
    gatorade* bola4;
    corazon* bola5;
    botiquin* bola6;
    chaleco* bola8;
    botiquin* bola9;
    corazon* bola10;

    Enemigo1* enemigo1;
    Enemigo2* enemigo2;
    Enemigo2* enemigo22;
    Enemigo3* enemigo3;
    QTimer *timer;

    int vidaMAX = 110;
    int vidaMOM = 110;
    int ATK = 60;
    int chalecos = 0;

    int puntuacion;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

};
#endif // MAINWINDOW_H
