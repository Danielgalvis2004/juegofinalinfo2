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
    escena->setSceneRect(0, 0, 700, 400); // Establece el rectángulo de la escena
    fondo->setPos(0, 0); // Establece la posición del fondo en la escena
    fondo->setPixmap(QPixmap(":/new/prefix1/Imagen/mapCIUDSd.png").scaled(700, 400)); // Asigna una imagen al fondo
    escena->addItem(fondo); // Agrega el fondo a la escena

    piano = new QGraphicsPixmapItem; // Crea un elemento de mapa de pixeles para piano
    piano->setPos(80, 20); // Establece la posición inicial de piano en la escena
    piano->setPixmap(QPixmap(":/new/prefix1/Imagen/piano.png").scaled(40, 40)); // Asigna una imagen a piano
    escena->addItem(piano); // Agrega piano a la escena

    cr71 = new QGraphicsPixmapItem;
    cr71->setPos(50, 100);
    cr71->setPixmap(QPixmap(":/new/prefix1/Imagen/nuevo.png").scaled(120, 280));
    escena->addItem(cr71); // Agrega cr71 a la escena

    ene1 = new QGraphicsPixmapItem;
    ene1->setPos(550, 100);
    ene1->setPixmap(QPixmap(":/new/prefix1/Imagen/ten hag.png").scaled(120, 280));
    escena->addItem(ene1); // Agrega ene1 a la escena

    // Iniciar el temporizador para la caída libre
    QTimer* temporizador = new QTimer(this);
    connect(temporizador, &QTimer::timeout, this, &MainWindow::caidaLibrePiano);
    temporizador->start(10);
}

void MainWindow::caidaLibrePiano()
{
    qreal posYActual = piano->y();
    qreal posYObjetivo = 100; // Posición objetivo donde el piano debe desaparecer (ajusta según tus necesidades)
    qreal velocidadCaida = 0.5;

    if (posYActual >= posYObjetivo)
    {

        escena->removeItem(piano);
        delete piano;
        piano = nullptr;
        return;
    }

    piano->setY(posYActual + velocidadCaida);
}

MainWindow::~MainWindow()
{
    delete ui;
}




