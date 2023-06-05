#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    escena = new QGraphicsScene(0,0,700,400);
    ciudad = new QGraphicsPixmapItem;
    ui->graphicsView->setScene(escena);

    ciudad->setPos(0,0);
    ciudad->setPixmap(QPixmap(":/new/prefix1/BATALLA/mapCIUDSd.png").scaled(700,400));
    escena->addItem(ciudad);

    balo= new QGraphicsPixmapItem;
    balo->setPos(170,200);
    balo->setPixmap(QPixmap(":/new/prefix1/BATALLA/BALON1.png").scaled(70,70));

    bruno = new QGraphicsPixmapItem; // Crea un elemento de mapa de pixeles para Bruno
    bruno->setPos(320,250); // Establece la posición inicial de Bruno en la escena
    bruno->setPixmap(QPixmap(":/new/prefix1/BATALLA/guayoimp.png").scaled(70,70)); // Asigna una imagen a Bruno

    jugador = new jugador1();
    escena->addItem(jugador);
    jugador->setPos(50,100);
    enemigo = new Enemigo1();
    escena->addItem(enemigo);
    enemigo->setPos(550,100);

    vidaJ = 110;
    ataqueJ = 60;
    vidaE1 = 100;
    ataqueE1 = 50;

    QAT = 1;

    if (QAT == 0){
        col = 0;
        escena->addItem(balo);
        // Configurar el temporizador
        start1 = balo->pos();

        timer1 = new QTimer(this); // Crea un temporizador
        connect(timer1, &QTimer::timeout, this, &MainWindow::movimientorecto); // Conecta la señal de timeout del temporizador a la función updateArmonicMotion
        timer1->start(20); // Inicia el temporizador para que se actualice cada 20 milisegundos

        if (balo->x()>550){
            delete balo;
        }

        QAT = 1;
    }
    if (QAT == 1){

        escena->addItem(bruno); // Agrega Bruno a la escena
        // Configurar el movimiento armónico simple
        amplitude = 170;                     // Ajusta la amplitud según sea necesario
        period = 2000;                       // Ajusta el período según sea necesario
        start = bruno->pos();                // Establecer el punto de inicio actual de Bruno
        destination = start + QPointF(-300, 0); // Establecer el punto de destino a la izquierda
        movingLeft = true;                   // Inicialmente, Bruno se moverá a la izquierda

        // Configurar el temporizador
        timer = new QTimer(this); // Crea un temporizador
        connect(timer, &QTimer::timeout, this, &MainWindow::updateArmonicMotion); // Conecta la señal de timeout del temporizador a la función updateArmonicMotion
        timer->start(20); // Inicia el temporizador para que se actualice cada 20 milisegundos

        if (bruno->collidesWithItem(enemigo)){
                escena->removeItem(bruno);
        }
        QAT = 0;
    }

}

void MainWindow::movimientorecto(){
    // Calcular la posición actual de Bruno en función del tiempo
    qreal time1 = QTime::currentTime().msecsSinceStartOfDay() % static_cast<int>(period); // Calcula el tiempo transcurrido desde el inicio del día y lo ajusta al período
    qreal x = start1.x() + 1*time1; //amplitude * qSin(2 * M_PI * time / period); // Calcula la nueva posición x de Bruno usando la función seno

    // Establecer la nueva posición de Bruno en la escena
    balo->setPos(x, start1.y());

    /*if (balo->x()>550){
        delete balo;
    }*/

}

void MainWindow::updateArmonicMotion()
{
    // Calcular la posición actual de Bruno en función del tiempo
    qreal time = QTime::currentTime().msecsSinceStartOfDay() % static_cast<int>(period); // Calcula el tiempo transcurrido desde el inicio del día y lo ajusta al período
    qreal x = start.x() - amplitude * qSin(2 * M_PI * time / period); // Calcula la nueva posición x de Bruno usando la función seno

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

