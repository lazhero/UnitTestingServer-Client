#include "mainwindow.h"

#include <QApplication>
#include"Graph.h"
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
