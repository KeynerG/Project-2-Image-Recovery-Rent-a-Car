#ifndef RENT_A_CAR_GRAPH_H
#define RENT_A_CAR_GRAPH_H

#include "./DataStructures/SimpleList/SimpleList.h"
#include "Edge.h"
#include "Vertex.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <QProgressBar>
#include <QVector>
#include <QThread>
#include <QTime>
#include "../../GraphicElements/Graph/EdgeItem.h"
#include "../../GraphicElements/Graph/VertexItem.h"

using namespace std;

/**
 * @class Graph
 * @brief Class for a vertex-dynamic and randomized connections graph.
 */
class Graph {
private:
    SimpleList<Edge> edgesList;
    SimpleList<Vertex> vertexList;

    SimpleList<Edge> sortedEdges;
    SimpleList<Edge> activeEdges;
    SimpleList<Edge> sortedActiveEdges;
    SimpleList<SimpleList<Edge>> possibleRoutes;
    SimpleList<Edge> finalRoute;
    int finalGasCapacity;
public:
    int getFinalGasCapacity() const;

    void setFinalGasCapacity(int finalGasCapacity);

public:
    /**
     * @brief Class default constructor.
     */
    Graph();

    /**
     * @brief edgesList getter.
     * @return edgesList
     */
    const SimpleList<Edge> &getEdgesList() const;

    /**
     * @brief edgesList setter.
     * @param edgesList
     */
    void setEdgesList(const SimpleList<Edge> &edgesList);

    /**
     * @brief vertexList getter.
     * @return vertex list
     */
    const SimpleList<Vertex> &getVertexList() const;

    /**
     * @brief vertexList setter.
     * @param vertexList
     */
    void setVertexList(const SimpleList<Vertex> &vertexList);

    /**
     * @brief sortedEdges getter.
     * @return sortedEdges
     */
    const SimpleList<Edge> &getSortedEdges() const;

    /**
     * @brief sortedEdges setter.
     * @param sortedEdges
     */
    void setSortedEdges(const SimpleList<Edge> &sortedEdges);

    /**
     * @brief activeEdges getter.
     * @return activeEdges
     */
    const SimpleList<Edge> &getActiveEdges() const;

    /**
     * @brief activeEdges setter.
     * @param activeEdges
     */
    void setActiveEdges(const SimpleList<Edge> &activeEdges);

    /**
     * @brief finalRoutes getter.
     * @return finalRoutes
     */
    const SimpleList<SimpleList<Edge>> &getFinalRoutes() const;

    /**
     * @brief finalRoutes setter.
     * @param finalRoutes
     */
    void setFinalRoutes(const SimpleList<SimpleList<Edge>> &finalRoutes);

    /**
     * @brief Function to add a new vertex in the graph.
     * @param name
     */
    void addVertex(string name);

    /**
     * @brief Function to add a new edge in the graph.
     * @param originId
     * @param destinyId
     */
    void addEdge(int originId, int destinyId);

    /**
     * @brief Function to add a new edge in the graph.
     * @param originId
     * @param destinyId
     * @param weight
     */
    void addEdge(int originId, int destinyId, int weight);

    /**
     * @brief Function to check if already exists a connection between originId and destinyId.
     * @param originId
     * @param destinyId
     * @return true if exists, false if it doesn't.
     */
    bool checkEdgeExistence(int originId, int destinyId);

    /**
     * @brief Function to sort the edgesList list.
     */
    void sortEdgesListByWeight();

    /**
     * @brief Function to sort the activeEdgesList list.
     */
    void sortActiveEdgesListByWeight();

    /**
     * @brief FUnction to generate a graph with n nodes and randomized connections.
     * @param nodes
     * @param progress
     */
    void generateGraphOf(int nodes, QProgressBar *progress);

    /**
     * @brief Function to get everything ready for bactracking progress.
     * @param originId
     * @param destinyId
     */
    void calculateBestRoute(int originId, int destinyId, QVector<VertexItem*> vertexItemList, QVector<EdgeItem*> edgeItemList);

    /**
     * @brief Function to calculate the best route between two nodes using backtracking.
     * @param originId
     * @param destinyId
     */
    void calculateBestRouteRecursive(int originId, int destinyId, QVector<VertexItem*> vertexItemList, QVector<EdgeItem*> edgeItemList);

    /**
     * @brief Function to print the finalRoute ist.
     */
    void printFinalRoute();

    /**
     * @brief Function to print the graph.
     */
    void printGraph();
};


#endif //RENT_A_CAR_GRAPH_H
