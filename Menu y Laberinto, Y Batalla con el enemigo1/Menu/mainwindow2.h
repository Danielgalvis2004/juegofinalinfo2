#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include "mainwindow1.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow2;
}
QT_END_NAMESPACE

class MainWindow2 : public QMainWindow {
    Q_OBJECT
public:
    MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

private:
    Ui::MainWindow2 *ui;
    QGraphicsScene *escena;
    QGraphicsPixmapItem *fondo;
    QGraphicsPixmapItem *cr7;
    void jugar();
    void salir();
    MainWindow1 X;
};

#endif // MAINWINDOW2_H
