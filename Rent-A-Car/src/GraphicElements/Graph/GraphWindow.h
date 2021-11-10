#ifndef RENT_A_CAR_GRAPHWINDOW_H
#define RENT_A_CAR_GRAPHWINDOW_H

#include <QGraphicsView>
#include <cmath>
#include <complex>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>

#include "src/DataStructures/SimpleList/SimpleList.h"
#include "src/LogicManagment/TravelAssistant.h"
#include "VertexItem.h"
#include "EdgeItem.h"

class GraphWindow : public QGraphicsView {
Q_OBJECT
private:
    QGraphicsScene *scene;
    TravelAssistant *travelAssistant = TravelAssistant::getInstance();
    SimpleList<complex<double>> positions;
    QStringList labelList;
    QLabel *originLabel;
    QComboBox *originBox;
    QLabel *destinyLabel;
    QComboBox *destinyBox;
    QPushButton *startButton;
    QPushButton *backButton;
    QPushButton *closeButton;
    QVector<EdgeItem *> edgeItemList;
    QVector<VertexItem *> vertexItemList;
    QWidget *parent;


    static complex<double> calculateNodePosition(int k, int n);

    void drawNodes(SimpleList<Vertex> routeList);

    void drawEdges(SimpleList<Edge> edgeList);

    void drawButtons(QStringList labelList);

public slots:

    void start();

    void goBack();

    void closeApp();

public:
    explicit GraphWindow(QWidget *parent = nullptr);

    ~GraphWindow();

    void drawGraph();
};


#endif //RENT_A_CAR_GRAPHWINDOW_H
