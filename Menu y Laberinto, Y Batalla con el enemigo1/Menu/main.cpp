#include "mainwindow1.h"
#include "mainwindow2.h"
#include "mainwindow.h"

#include "mainwindow3.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow2 w;
    w.show();
    return a.exec();
}
