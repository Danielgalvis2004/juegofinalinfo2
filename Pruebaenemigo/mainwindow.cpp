#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this); // Crea una escena gráfica
    fondo = new QGraphicsPixmapItem; // Crea un elemento de mapa de pixeles para el fondo
    ui->graphicsView->setScene(escena); // Asigna la escena gráfica a la vista gráfica
    escena->setSceneRect(0,0,700,400); // Establece el rectángulo de la escena
    fondo->setPos(0,0); // Establece la posición del fondo en la escena
    fondo->setPixmap(QPixmap(":/new/prefix1/Imagen/mapCIUDSd.png").scaled(700,400)); // Asigna una imagen al fondo
    bruno = new QGraphicsPixmapItem; // Crea un elemento de mapa de pixeles para Bruno
    bruno->setPos(300,100); // Establece la posición inicial de Bruno en la escena
    bruno->setPixmap(QPixmap(":/new/prefix1/Imagen/guayoimp.png").scaled(100,100)); // Asigna una imagen a Bruno
    escena->addItem(fondo); // Agrega el fondo a la escena
    escena->addItem(bruno); // Agrega Bruno a la escena

    // Configurar el movimiento armónico simple
    amplitude = 100;                     // Ajusta la amplitud según sea necesario
    period = 2000;                       // Ajusta el período según sea necesario
    start = bruno->pos();                // Establecer el punto de inicio actual de Bruno
    destination = start + QPointF(-200, 0); // Establecer el punto de destino a la izquierda
    movingLeft = true;                   // Inicialmente, Bruno se moverá a la izquierda

    // Configurar el temporizador
    timer = new QTimer(this); // Crea un temporizador
    connect(timer, &QTimer::timeout, this, &MainWindow::updateArmonicMotion); // Conecta la señal de timeout del temporizador a la función updateArmonicMotion
    timer->start(20); // Inicia el temporizador para que se actualice cada 20 milisegundos
}

void MainWindow::updateArmonicMotion()
{
    // Calcular la posición actual de Bruno en función del tiempo
    qreal time = QTime::currentTime().msecsSinceStartOfDay() % static_cast<int>(period); // Calcula el tiempo transcurrido desde el inicio del día y lo ajusta al período
    qreal x = start.x() + amplitude * qSin(2 * M_PI * time / period); // Calcula la nueva posición x de Bruno usando la función seno

    // Establecer la nueva posición de Bruno en la escena
    bruno->setPos(x, start.y());

    // Comprobar si Bruno ha llegado al punto de destino
    if (qAbs(x - destination.x()) < 1e-6) {
        // Invertir la dirección de movimiento
        movingLeft = !movingLeft;

        // Actualizar el punto de inicio y destino
        start = bruno->pos();
        destination = start + QPointF(movingLeft ? -200 : 200, 0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
