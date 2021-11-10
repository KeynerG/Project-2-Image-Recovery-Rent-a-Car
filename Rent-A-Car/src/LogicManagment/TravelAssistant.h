#ifndef RENT_A_CAR_TRAVELASSISTANT_H
#define RENT_A_CAR_TRAVELASSISTANT_H

#include <iostream>
#include <QProgressBar>
#include <QVector>

#include "src/DataStructures/Graph/Graph.h"
#include "src/GraphicElements/Graph/VertexItem.h"
#include "src/GraphicElements/Graph/EdgeItem.h"

using namespace std;

/**
 * @class TravelAssistant
 */
class TravelAssistant {
private:
    Graph routes;
    static TravelAssistant *instance;

protected:
    /**
     * @brief Class default constructor.
     */
    TravelAssistant();

public:
    /**
     * @brief routes getter.
     * @return routes
     */
    const Graph &getRoutes() const;

    /**
     * @brief routes setter.
     * @param routes
     */
    void setRoutes(const Graph &routes);

    /**
     * @brief Function to generate the graph.
     * @param cities
     * @param progress
     */
    void generateRoutes(int cities, QProgressBar *progress);

    /**
     * @brief Function to  calculate the best route between two points (Backtracking)
     * @param originId
     * @param destinyId
     * @param vertexItemList
     * @param edgeItemList
     */
    void
    calculateRoute(int originId, int destinyId, QVector<VertexItem *> vertexItemList, QVector<EdgeItem *> edgeItemList);

    /**
     * @brief Singleton function.
     * @param other
     */
    TravelAssistant(TravelAssistant &other) = delete;

    /**
     * @brief Singleton function.
     */
    void operator=(const TravelAssistant &) = delete;

    /**
     * @brief Singleton function - instance getter.
     * @return instance.
     */
    static TravelAssistant *getInstance();
};


#endif //RENT_A_CAR_TRAVELASSISTANT_H
