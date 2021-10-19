#include "mainwindow.h"
#include "DataStructures/Graph/Graph.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <QApplication>

int main(int argc, char *argv[]) {

    Graph g;
    g.generateGraphOf(5);
    g.printGraph();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
