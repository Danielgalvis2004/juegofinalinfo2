/*#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow3;
}
QT_END_NAMESPACE

class MainWindow3 : public QMainWindow {
    Q_OBJECT
public:
    MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow3 *ui;
    QGraphicsScene *escena;
    QGraphicsPixmapItem *fondo;
    QGraphicsPixmapItem *cr7;

};

#endif // MAINWINDOW3_H

*/
