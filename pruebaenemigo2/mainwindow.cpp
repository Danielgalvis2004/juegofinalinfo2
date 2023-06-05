#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QTimer>

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
    piano = new QGraphicsPixmapItem; // Crea un elemento de mapa de pixeles para piano
    piano->setPos(300,100); // Establece la posición inicial de piano en la escena
    piano->setPixmap(QPixmap(":/new/prefix1/Imagen/piano.png").scaled(100,100)); // Asigna una imagen a piano
    escena->addItem(fondo); // Agrega el fondo a la escena
    escena->addItem(piano); // Agrega piano a la escena
    // Iniciar el temporizador para la caída libre
    QTimer* temporizador = new QTimer(this);
    connect(temporizador, &QTimer::timeout, this, &MainWindow::caidaLibrePiano); //creamos temporizadpr
    temporizador->start(10); //inicia temporizador
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::caidaLibrePiano()
{
    // Obtener la posición actual del piano
    qreal posYActual = piano->y();

    // Definir la posición objetivo donde el piano debe desaparecer
    qreal posYObjetivo = 300;

    // Definir la velocidad de caída (valor incremental)
    qreal velocidadCaida = 1;

    // Comprobar si el piano ha alcanzado la posición objetivo
    if (posYActual >= posYObjetivo)
    {
        // El piano ha alcanzado la posición objetivo, eliminarlo de la escena
        escena->removeItem(piano);
        delete piano;
        piano = nullptr;

        // Detener el temporizador (opcional, si no lo necesitas para nada más)
        QTimer::singleShot(0, this, [this]() {
            sender()->deleteLater();
        });

        return;
    }

    // Mover el piano hacia abajo según la velocidad de caída
    piano->setY(posYActual + velocidadCaida);
}






