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
    this->routes.printGraph();
}

void TravelAssistant::clculateRoute(int originId, int destinyId) {
    //Codigo del backtracking
}

TravelAssistant *TravelAssistant::getInstance() {
    if (instance == nullptr) {
        instance = new TravelAssistant();
    }
    return instance;
}

