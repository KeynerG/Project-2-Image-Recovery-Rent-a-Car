#ifndef RENT_A_CAR_GRAPHWINDOW_H
#define RENT_A_CAR_GRAPHWINDOW_H

#include <QGraphicsView>
#include <../DataStructures/SimpleList/SimpleList.h>
#include "../../LogicManagment/TravelAssistant.h"
#include "VertexItem.h"
#include "EdgeItem.h"
#include <cmath>
#include <complex>
#include <QComboBox>
#include <QPushButton>

class GraphWindow: public QGraphicsView{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    TravelAssistant* travelAssistant = TravelAssistant::getInstance();
    SimpleList<complex<double>> positions;
    QStringList labelList;
    QLabel* originLabel;
    QComboBox* originBox;
    QLabel* destinyLabel;
    QComboBox* destinyBox;
    QPushButton* startButton;
    SimpleList<EdgeItem*>* edgeItemList;


    static complex<double> calculateNodePosition(int k, int n);
    void drawNodes(SimpleList<Vertex> routeList);
    void drawEdges(SimpleList<Edge> edgeList);
    void drawButtons(QStringList labelList);
public slots:
    void start();
public:
    explicit GraphWindow(QWidget *parent = nullptr);
    void drawGraph();
};


#endif //RENT_A_CAR_GRAPHWINDOW_H
