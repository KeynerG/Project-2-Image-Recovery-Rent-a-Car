#include "Graph.h"

Graph::Graph() {
    this->edgesList = SimpleList<Edge>();
    this->vertexList = SimpleList<Vertex>();
}

const SimpleList<Edge> &Graph::getEdgesList() const {
    return edgesList;
}

void Graph::setEdgesList(const SimpleList<Edge> &edgesList) {
    Graph::edgesList = edgesList;
}

const SimpleList<Vertex> &Graph::getVertexList() const {
    return vertexList;
}

void Graph::setVertexList(const SimpleList<Vertex> &vertexList) {
    Graph::vertexList = vertexList;
}

void Graph::addVertex(string name) {
    Vertex toAdd = Vertex(to_string(this->vertexList.len + 1), name);
    vertexList.addNodeAtEnd(toAdd);
}

void Graph::addEdge(int origindId, int destinyId) {
    Edge toAdd = Edge(to_string(this->edgesList.len + 1), this->vertexList.getNodeIn(origindId - 1),
                      this->vertexList.getNodeIn(destinyId - 1));
    edgesList.addNodeAtEnd(toAdd);
}

void Graph::addEdge(int origindId, int destinyId, int weight) {
    Edge toAdd = Edge(to_string(this->edgesList.len + 1), this->vertexList.getNodeIn(origindId - 1),
                      this->vertexList.getNodeIn(destinyId - 1), weight);
    edgesList.addNodeAtEnd(toAdd);
}

bool Graph::checkEdgeExistence(int originId, int destinyId) {
    SimpleNode<Edge> *edgeAux = this->edgesList.head;
    while (edgeAux != nullptr) {
        if (stoi(edgeAux->getData().getOrigin().getId()) == originId and
            stoi(edgeAux->getData().getDestiny().getId()) == destinyId) {
            return true;
        } else {
            edgeAux = edgeAux->getNext();
        }
    }
    return false;
}

void Graph::generateGraphOf(int nodes, QProgressBar *progress) {
    this->vertexList = SimpleList<Vertex>();
    this->edgesList = SimpleList<Edge>();
    progress->setValue(0);

    for (int i = 0; i < nodes; i++) {
        addVertex("City " + to_string(this->vertexList.len + 1));
    }

    progress->setValue(10);

    for (int i = 1; i < this->vertexList.len + 1; i++) {

        progress->setValue(i * 100 / this->vertexList.len);

        // Generates a random number for the individual vertex connections
        srand(time(0));
        int vertexConnections;
        if (nodes == 4) {
            vertexConnections = (rand() % 3) + 1;
        } else {
            vertexConnections = (rand() % 4) + 1;
        }

        for (int j = 0; j < vertexConnections; j++) {

            // Generates a random number to select the vertex to connect
            srand(time(0));
            int vertexToConnect = (rand() % (this->vertexList.len)) + 1;

            // Generates a random number for the edge weight
            srand(time(0));
            int randomizedWeight = (rand() % 90) + 10;

            if (vertexToConnect != i and !checkEdgeExistence(i, vertexToConnect)) {
                if (this->edgesList.head == nullptr) {
                    addEdge(i, vertexToConnect, randomizedWeight);
                } else if (vertexToConnect != stoi(this->edgesList.tail->getData().getDestiny().getId()) or
                           randomizedWeight != this->edgesList.tail->getData().getWeight()) {
                    addEdge(i, vertexToConnect, randomizedWeight);
                } else {
                    j--;
                }
            } else {
                j--;
            }
        }
    }
    progress->setValue(100);
}

void Graph::printGraph() {
    cout << "Graph:" << endl << endl;
    cout << "Vertex list:" << endl;
    SimpleNode<Vertex> *vertexAux = this->vertexList.head;
    while (vertexAux != nullptr) {
        cout << "Vertex data - ID: " << vertexAux->getData().getId() << ", name: " << vertexAux->getData().getName()
             << "." << endl;
        vertexAux = vertexAux->getNext();
    }
    cout << endl << endl << "Edges list:" << endl;
    SimpleNode<Edge> *edgeAux = this->edgesList.head;
    while (edgeAux != nullptr) {
        cout << "Edge data - ID: " << edgeAux->getData().getId() << ", origin: "
             << edgeAux->getData().getOrigin().getId() << ", destiny: " << edgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(edgeAux->getData().getWeight()) << "." << endl;
        edgeAux = edgeAux->getNext();
    }
}
