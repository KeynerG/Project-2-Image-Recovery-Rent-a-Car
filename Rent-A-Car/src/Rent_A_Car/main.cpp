#include "mainwindow.h"
#include "DataStructures/Graph/Graph.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    Graph g;
    g.addVertex("1", "PZ");
    g.addVertex("2", "Chepe");
    g.addVertex("3", "TR");
    g.addEdge(1,3);
    g.addEdge(1, 2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.printGraph();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
