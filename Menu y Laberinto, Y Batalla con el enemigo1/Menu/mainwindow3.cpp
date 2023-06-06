/*#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    fondo = new QGraphicsPixmapItem;
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,400,300);
    fondo->setPos(0,0);
    fondo->setPixmap(QPixmap("://IMAGENES/noche.png").scaled(400,300));
    //cr7 = new QGraphicsPixmapItem;
    //cr7->setPos(200,100);
    //cr7->setPixmap(QPixmap("://IMAGENES/new.png").scaled(200,200));
    escena->addItem(fondo);
    //escena->addItem(cr7);
    // Crear el título
    QGraphicsTextItem* titulo = new QGraphicsTextItem("YOU WIN");
    QFont font;
    font.setPointSize(28);
    titulo->setFont(font);
    titulo->setPos(60, 50);
    font.setFamily("Arial");
    titulo->setDefaultTextColor(Qt::red);
    escena->addItem(titulo);

    /* texto
    QGraphicsTextItem* texto = new QGraphicsTextItem("BY: Daniel Galvis and Camilo Medina");
    font.setPointSize(10);
    texto->setFont(font);
    texto->setPos(65, 100);
    font.setFamily("Verdana");
    texto->setDefaultTextColor(Qt::darkCyan);
    escena->addItem(texto);

}
void MainWindow3::on_pushButton_clicked()
{
    QApplication::quit();
}


*/
