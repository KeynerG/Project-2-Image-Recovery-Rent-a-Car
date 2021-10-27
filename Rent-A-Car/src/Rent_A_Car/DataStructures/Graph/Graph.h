#ifndef RENT_A_CAR_GRAPH_H
#define RENT_A_CAR_GRAPH_H

#include "./DataStructures/SimpleList/SimpleList.h"
#include "Edge.h"
#include "Vertex.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <QProgressBar>

using namespace std;

class Graph {
private:
    SimpleList<Edge> edgesList;
    SimpleList<Vertex> vertexList;

    SimpleList<Edge> sortedEdges;
    SimpleList<Edge> activeEdges;
    SimpleList<Edge> sortedActiveEdges;
    SimpleList<SimpleList<Edge>> possibleRoutes;
    SimpleList<Edge> finalRoute;

public:
    Graph();

    const SimpleList<Edge> &getEdgesList() const;

    void setEdgesList(const SimpleList<Edge> &edgesList);

    const SimpleList<Vertex> &getVertexList() const;

    void setVertexList(const SimpleList<Vertex> &vertexList);

    const SimpleList<Edge> &getSortedEdges() const;

    void setSortedEdges(const SimpleList<Edge> &sortedEdges);

    const SimpleList<Edge> &getActiveEdges() const;

    void setActiveEdges(const SimpleList<Edge> &activeEdges);

    const SimpleList<SimpleList<Edge>> &getFinalRoutes() const;

    void setFinalRoutes(const SimpleList<SimpleList<Edge>> &finalRoutes);

    void addVertex(string name);

    void addEdge(int originId, int destinyId);

    void addEdge(int originId, int destinyId, int weight);

    bool checkEdgeExistence(int originId, int destinyId);

    void sortEdgesListByWeight();

    void sortActiveEdgesListByWeight();

    void generateGraphOf(int nodes, QProgressBar *progress);

    void calculateBestRoute(int originId, int destinyId);

    void calculateBestRouteRecursive(int originId, int destinyId);

    void printFinalRoute();

    void printGraph();
};


#endif //RENT_A_CAR_GRAPH_H
