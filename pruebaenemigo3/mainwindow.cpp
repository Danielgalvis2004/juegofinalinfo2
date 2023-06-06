#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QTimer>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    fondo = new QGraphicsPixmapItem;
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,700,400);
    fondo->setPos(0,0);
    fondo->setPixmap(QPixmap(":/new/prefix1/Imagen/mapCIUDSd.png").scaled(700,400));
    camara = new QGraphicsPixmapItem;
    camara->setPos(550,200);
    camara->setPixmap(QPixmap(":/new/prefix1/Imagen/camara.png").scaled(70,70));
    escena->addItem(fondo);
    escena->addItem(camara);
    cr71 = new QGraphicsPixmapItem;
    cr71->setPos(50, 100);
    cr71->setPixmap(QPixmap(":/new/prefix1/Imagen/nuevo.png").scaled(120, 280));
    escena->addItem(cr71); // Agrega cr71 a la escena
    ene2 = new QGraphicsPixmapItem;
    ene2->setPos(550, 100);
    ene2->setPixmap(QPixmap(":/new/prefix1/Imagen/periodista.png").scaled(120, 280));
    escena->addItem(ene2); // Agrega ene1 a la escena

    // Parámetros del movimiento parabólico
       double gravedad = 9.8; // Aceleración debida a la gravedad en m/s^2
       double velocidadInicial = 40; // Velocidad inicial en m/s
       double angulo = 45; // Ángulo de lanzamiento en grados
       double radianes = angulo * M_PI / 180.0; // Conversión a radianes
       double tiempoVuelo = (2 * velocidadInicial * sin(radianes)) / gravedad; // Tiempo de vuelo en segundos
       double distanciaHorizontal = velocidadInicial * cos(radianes) * tiempoVuelo; // Distancia horizontal en metros

       // Cálculo de la trayectoria parabólica
       double tiempoIncremento = 0.1; // Incremento de tiempo para actualizar la posición de la cámara
       tiempo = 0.0; // Tiempo actual
       double alturaInicial = camara->y(); // Altura inicial de la cámara
       double velocidadVerticalInicial = velocidadInicial * sin(radianes); // Velocidad vertical inicial


       // Temporizador para actualizar la posición de la cámara
       QTimer *timer = new QTimer(this);
       connect(timer, &QTimer::timeout, this, [=]() {
           double posicionHorizontal = velocidadInicial * cos(radianes) * tiempo; // Posición horizontal actual
           double posicionVertical = alturaInicial + (velocidadVerticalInicial * tiempo) - (0.5 * gravedad * tiempo * tiempo); // Posición vertical actual

           // Actualizar la posición de la cámara en la escena
           camara->setPos(posicionHorizontal, posicionVertical);

           // Verificar si la cámara ha llegado a su destino
           if (posicionHorizontal <= 170) {
               tiempo += tiempoIncremento;
           } else {
               // La cámara ha llegado a su destino, detener el temporizador y eliminar la cámara
               timer->stop();
               escena->removeItem(camara);
               delete camara;
           }
       });

       // Iniciar el temporizador para actualizar la posición de la cámara cada 100 milisegundos
       timer->start(100);
   }
MainWindow::~MainWindow()
{
    delete ui;
}
