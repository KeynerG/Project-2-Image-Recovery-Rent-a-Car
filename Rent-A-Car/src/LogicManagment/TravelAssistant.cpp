#include "TravelAssistant.h"

TravelAssistant *TravelAssistant::instance = nullptr;

TravelAssistant::TravelAssistant() {
    this->routes = Graph();
}

const Graph &TravelAssistant::getRoutes() const {
    return routes;
}

void TravelAssistant::setRoutes(const Graph &routes) {
    TravelAssistant::routes = routes;
}

void TravelAssistant::generateRoutes(int cities, QProgressBar *progress) {
    this->routes.generateGraphOf(cities, progress);
}

void TravelAssistant::calculateRoute(int originId, int destinyId, QVector<VertexItem *> vertexItemList,
                                     QVector<EdgeItem *> edgeItemList) {
    this->routes.calculateBestRoute(originId, destinyId, vertexItemList, edgeItemList);
}

TravelAssistant *TravelAssistant::getInstance() {
    if (instance == nullptr) {
        instance = new TravelAssistant();
    }
    return instance;
}