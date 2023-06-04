#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    fondo = new QGraphicsPixmapItem;
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,400,300);
    fondo->setPos(0,0);
    fondo->setPixmap(QPixmap("://IMAGENES/noche.png").scaled(400,300));
    cr7 = new QGraphicsPixmapItem;
    cr7->setPos(200,100);
    cr7->setPixmap(QPixmap("://IMAGENES/new.png").scaled(200,200));
    escena->addItem(fondo);
    escena->addItem(cr7);
    // Crear el título
    QGraphicsTextItem* titulo = new QGraphicsTextItem("BATTLE LABYRINTH");
    QFont font;
    font.setPointSize(24);
    titulo->setFont(font);
    titulo->setPos(60, 50);
    font.setFamily("Arial");
    titulo->setDefaultTextColor(Qt::red);
    escena->addItem(titulo);

    // texto
    QGraphicsTextItem* texto = new QGraphicsTextItem("BY: Daniel Galvis and Camilo Medina");
    font.setPointSize(10);
    texto->setFont(font);
    texto->setPos(65, 100);
    font.setFamily("Verdana");
    texto->setDefaultTextColor(Qt::darkCyan);
    escena->addItem(texto);

}

void MainWindow::jugar()
{
    // Lógica del juego
    // Resto del código del juego...
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{

}


void MainWindow::on_pushButton_2_clicked(bool checked)
{
    QApplication::quit();
}

