#ifndef RENT_A_CAR_GRAPH_H
#define RENT_A_CAR_GRAPH_H

#import "./DataStructures/SimpleList/SimpleList.h"
#import "Edge.h"
#import "Vertex.h"

#import <iostream>
#import <ctime>
#import <cstdlib>

using namespace std;

class Graph {
private:
    SimpleList<Edge> edgesList;
    SimpleList<Vertex> vertexList;

public:
    Graph();

    const SimpleList<Edge> &getEdgesList() const;

    void setEdgesList(const SimpleList<Edge> &edgesList);

    const SimpleList<Vertex> &getVertexList() const;

    void setVertexList(const SimpleList<Vertex> &vertexList);

    void addVertex(string name);

    void addEdge(int originId, int destinyId);

    void addEdge(int originId, int destinyId, int weight);

    bool checkEdgeExistence(int originId, int destinyId);

    void generateGraphOf(int nodes);

    void printGraph();
};


#endif //RENT_A_CAR_GRAPH_H
