#ifndef RENT_A_CAR_TRAVELASSISTANT_H
#define RENT_A_CAR_TRAVELASSISTANT_H

#include <iostream>
#include <QProgressBar>
#include <QVector>
#include <DataStructures/Graph/Graph.h>
#include <../GraphicElements/Graph/VertexItem.h>
#include "../GraphicElements/Graph/EdgeItem.h"

using namespace std;

class TravelAssistant {
private:
    Graph routes;
    static TravelAssistant *instance;
protected:
    TravelAssistant();

public:
    const Graph &getRoutes() const;

    void setRoutes(const Graph &routes);

    void generateRoutes(int cities, QProgressBar *progress);

    void
    calculateRoute(int originId, int destinyId, QVector<VertexItem *> vertexItemList, QVector<EdgeItem *> edgeItemList);

    TravelAssistant(TravelAssistant &other) = delete;

    void operator=(const TravelAssistant &) = delete;

    static TravelAssistant *getInstance();
};


#endif //RENT_A_CAR_TRAVELASSISTANT_H
