#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsPixmapItem *fondo;
    QGraphicsPixmapItem *bruno;
    qreal amplitude;     // Amplitud del movimiento
    qreal period;        // Período del movimiento en milisegundos
    QPointF start;       // Punto de inicio actual de Bruno
    QPointF destination; // Punto de destino a la izquierda
    bool movingLeft;     // Indicador de dirección de movimiento
    QTimer* timer;       // Temporizador para actualizar el movimiento
    void updateArmonicMotion();
};


