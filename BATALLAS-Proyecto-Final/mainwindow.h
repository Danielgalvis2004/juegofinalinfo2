#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include "objetos.h"
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    QGraphicsPixmapItem *ciudad;
    jugador1* jugador;
    Enemigo1* enemigo;
    int QAT;
    QGraphicsPixmapItem* balo;
    QPointF start1;
    QTimer* timer1;
    int col;
    int vidaJ;
    int ataqueJ;
    int vidaE1;
    int ataqueE1;

    QGraphicsPixmapItem *bruno;
    qreal amplitude;     // Amplitud del movimiento
    qreal period;        // Período del movimiento en milisegundos
    QPointF start;       // Punto de inicio actual de Bruno
    QPointF destination; // Punto de destino a la izquierda
    bool movingLeft;     // Indicador de dirección de movimiento
    QTimer* timer;       // Temporizador para actualizar el movimiento


    void updateArmonicMotion();
    void movimientorecto();
};
#endif // MAINWINDOW_H
