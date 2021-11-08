#include "GraphicElements/Graph/GraphWindow.h"
GraphWindow::GraphWindow(QWidget *parent) {
    setBackgroundBrush(QColor(""));
    scene = new QGraphicsScene(0,0,800,600);
    setScene(scene);
    this->setWindowTitle("Rent A Car");
    this->setStyleSheet("background-color:#001010");
}

void GraphWindow::drawGraph() {
    this->drawNodes();
    //drawEdges();
}

void GraphWindow::drawNodes() {
    for(int i = 0; i < this->routes.getVertexList().len; i++){
        VertexItem *v = new VertexItem(this->routes.getVertexList().getNodeIn(i).getId());
        this->scene->addItem(v);
        nodes.addNodeAtEnd(v);
    }
}