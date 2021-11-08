#ifndef RENT_A_CAR_GRAPHWINDOW_H
#define RENT_A_CAR_GRAPHWINDOW_H

#include <QGraphicsView>
#include <DataStructures/SimpleList/SimpleList.h>
#include <LogicManagment/TravelAssistant.h>
#include "VertexItem.h"
#include "EdgeItem.h"

class GraphWindow: public QGraphicsView{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    TravelAssistant* travelAssistant = travelAssistant->getInstance();
    Graph routes = travelAssistant->getRoutes();
    SimpleList<VertexItem*> nodes;
    SimpleList<EdgeItem*> edges;
    void drawNodes();
    void drawEdges();
public:
    explicit GraphWindow(QWidget *parent = nullptr);
    void drawGraph();
};


#endif //RENT_A_CAR_GRAPHWINDOW_H
