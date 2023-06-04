#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QApplication>

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

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsPixmapItem *fondo;
    QGraphicsPixmapItem *cr7;
    void jugar();
    void salir();
};

#endif // MAINWINDOW_H
