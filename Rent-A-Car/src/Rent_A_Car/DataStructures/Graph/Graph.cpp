#include <GraphicElements/Graph/VertexItem.h>
#include <QCoreApplication>
#include "Graph.h"

Graph::Graph() {
    this->edgesList = SimpleList<Edge>();
    this->vertexList = SimpleList<Vertex>();
    this->sortedEdges = SimpleList<Edge>();
    this->activeEdges = SimpleList<Edge>();
    this->possibleRoutes = SimpleList<SimpleList<Edge>>();

    this->possibleRoutes.setHead(nullptr);
    this->possibleRoutes.setTail(nullptr);
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

const SimpleList<Edge> &Graph::getSortedEdges() const {
    return sortedEdges;
}

void Graph::setSortedEdges(const SimpleList<Edge> &sortedEdges) {
    Graph::sortedEdges = sortedEdges;
}

const SimpleList<Edge> &Graph::getActiveEdges() const {
    return activeEdges;
}

void Graph::setActiveEdges(const SimpleList<Edge> &activeEdges) {
    Graph::activeEdges = activeEdges;
}

const SimpleList<SimpleList<Edge>> &Graph::getFinalRoutes() const {
    return possibleRoutes;
}

void Graph::setFinalRoutes(const SimpleList<SimpleList<Edge>> &finalRoutes) {
    Graph::possibleRoutes = finalRoutes;
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

void Graph::sortEdgesListByWeight() {
    SimpleList<Edge> edgesListCopy;
    SimpleNode<Edge> *ctrlC = this->edgesList.head;
    while (ctrlC != nullptr) {
        edgesListCopy.addNodeAtEnd(ctrlC->getData());
        ctrlC = ctrlC->getNext();
    }

    while (edgesListCopy.len > 0) {
        SimpleNode<Edge> *minWeight = edgesListCopy.head;
        SimpleNode<Edge> *aux = edgesListCopy.head->getNext();
        while (aux != nullptr) {
            if (aux->getData().getWeight() <= minWeight->getData().getWeight()) {
                minWeight = aux;
            }
            aux = aux->getNext();
        }
        this->sortedEdges.addNodeAtEnd(minWeight->getData());
        edgesListCopy.deleteNode(minWeight);
    }
}

void Graph::sortActiveEdgesListByWeight() {
    SimpleList<Edge> activeEdgesListCopy;
    SimpleNode<Edge> *ctrlC = this->activeEdges.head;
    while (ctrlC != nullptr) {
        activeEdgesListCopy.addNodeAtEnd(ctrlC->getData());
        ctrlC = ctrlC->getNext();
    }

    ctrlC = this->sortedActiveEdges.head;
    while (ctrlC != nullptr) {
        activeEdgesListCopy.addNodeAtEnd(ctrlC->getData());
        ctrlC = ctrlC->getNext();
    }

    activeEdges.clearList();
    sortedActiveEdges.clearList();

    while (activeEdgesListCopy.len > 0) {
        SimpleNode<Edge> *minWeight = activeEdgesListCopy.head;
        SimpleNode<Edge> *aux = activeEdgesListCopy.head->getNext();
        while (aux != nullptr) {
            if (aux->getData().getWeight() <= minWeight->getData().getWeight()) {
                minWeight = aux;
            }
            aux = aux->getNext();
        }
        this->sortedActiveEdges.addNodeAtEnd(minWeight->getData());
        activeEdgesListCopy.deleteNode(minWeight);
    }
}

void Graph::generateGraphOf(int nodes, QProgressBar *progress) {
    this->vertexList.clearList();
    this->edgesList.clearList();

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
            vertexConnections = (rand() % 2) + 1;
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

    //Optimizes edges, deleting duplicates (inverted)
    SimpleNode<Edge> *current = edgesList.head;
    while (current != edgesList.tail) {
        SimpleNode<Edge> *nextOnes = current->getNext();
        while (nextOnes != nullptr) {
            if ((current->getData().getOrigin().getId() == nextOnes->getData().getOrigin().getId() and
                 current->getData().getDestiny().getId() == nextOnes->getData().getDestiny().getId()) or
                (current->getData().getOrigin().getId() == nextOnes->getData().getDestiny().getId() and
                 current->getData().getDestiny().getId() == nextOnes->getData().getOrigin().getId())) {
                edgesList.deleteNode(nextOnes);
            }
            nextOnes = nextOnes->getNext();
        }
        current = current->getNext();
    }

    progress->setValue(100);
}

void Graph::calculateBestRoute(int originId, int destinyId, QVector<VertexItem *> vertexItemList,
                               QVector<EdgeItem *> edgeItemList) {
    sortedEdges.clearList();
    activeEdges.clearList();
    sortedActiveEdges.clearList();
    possibleRoutes.clearList();
    finalRoute.clearList();

    sortEdgesListByWeight();

    QBrush b;
    b.setStyle(Qt::SolidPattern);
    b.setColor("#004040");
    QPen p;
    p.setStyle(Qt::SolidLine);

    p.setColor("#00ffff");
    for (int i = 0; i < edgeItemList.size(); ++i) {
        edgeItemList[i]->setPen(p);
    }

    for (int i = 0; i < vertexItemList.size(); ++i) {
        vertexItemList[i]->setBrush(b);
        vertexItemList[i]->setPen(p);
    }

    calculateBestRouteRecursive(originId, destinyId, vertexItemList, edgeItemList);
}

void Graph::calculateBestRouteRecursive(int originId, int destinyId, QVector<VertexItem *> vertexItemList,
                                        QVector<EdgeItem *> edgeItemList) {
    // Breaking case: If the route is finished
    if (originId == destinyId) {
        SimpleNode<SimpleList<Edge>> *bestRoute = this->possibleRoutes.head;
        while (bestRoute != nullptr) {
            if (stoi(bestRoute->getData().tail->getData().getDestiny().getId()) == destinyId) {
                SimpleNode<Edge> *edg = bestRoute->getData().head;
                while (edg != nullptr) {
                    this->finalRoute.addNodeAtEnd(edg->getData());
                    edg = edg->getNext();
                }
                SimpleNode<Edge> *fEdgeAux = this->finalRoute.head;
                finalGasCapacity = fEdgeAux->getData().getWeight();
                while (fEdgeAux != nullptr) {
                    if (fEdgeAux->getData().getWeight() > finalGasCapacity) {
                        finalGasCapacity = fEdgeAux->getData().getWeight();
                    }
                    fEdgeAux = fEdgeAux->getNext();
                }
                printFinalRoute();
                return;
            } else {
                bestRoute = bestRoute->getNext();
            }
        }
    }

    // Activates all useful connections.
    SimpleNode<Edge> *usefulConnection = this->sortedEdges.head;
    while (usefulConnection != nullptr) {
        if (stoi(usefulConnection->getData().getDestiny().getId()) == originId) {
            //usefulConnection->getData().invertOriginDestiny();
            Edge conn = Edge(usefulConnection->getData().getId(), usefulConnection->getData().getDestiny(),
                             usefulConnection->getData().getOrigin(), usefulConnection->getData().getWeight());
            activeEdges.addNodeAtEnd(conn);

            SimpleNode<Edge> *del = usefulConnection;
            usefulConnection = usefulConnection->getNext();

            sortedEdges.deleteNode(del);
        } else if (stoi(usefulConnection->getData().getOrigin().getId()) == originId) {
            activeEdges.addNodeAtEnd(usefulConnection->getData());
            SimpleNode<Edge> *del = usefulConnection;
            usefulConnection = usefulConnection->getNext();

            sortedEdges.deleteNode(del);
        } else {
            usefulConnection = usefulConnection->getNext();
        }
    }

    // Sorts the list of active connections.
    sortActiveEdgesListByWeight();

    // Gets the best connection on active connections.
    SimpleNode<Edge> *bestConnection = sortedActiveEdges.head;

    // Determines which node is the program moving to.
    int movingToNode = stoi(bestConnection->getData().getDestiny().getId());

    // Adds the best connection in a "possible routes" list. Saves the route made.
    SimpleList<Edge> possibleRoute;
    if (possibleRoutes.len <= 0) {
        possibleRoute.addNodeAtEnd(bestConnection->getData());
        possibleRoutes.addNodeAtEnd(possibleRoute);

        QBrush b;
        b.setStyle(Qt::SolidPattern);
        b.setColor("#004040");
        QPen p;
        p.setStyle(Qt::SolidLine);

        p.setColor("#00ffff");
        for (int i = 0; i < edgeItemList.size(); ++i) {
            edgeItemList[i]->setPen(p);
        }

        for (int i = 0; i < vertexItemList.size(); ++i) {
            vertexItemList[i]->setBrush(b);
            vertexItemList[i]->setPen(p);
        }

        p.setColor("#E74C3C");
        for (int i = 0; i < possibleRoute.len; ++i) {
            for (int j = 0; j < edgeItemList.size(); ++j) {
                if (possibleRoute.getNodeIn(i).getId() == edgeItemList[j]->getId()) {
                    edgeItemList[j]->setPen(p);
                }
            }
            for (int j = 0; j < vertexItemList.size(); ++j) {
                if (possibleRoute.getNodeIn(i).getOrigin().getId() == vertexItemList[j]->getIdentifier() or
                    possibleRoute.getNodeIn(i).getDestiny().getId() == vertexItemList[j]->getIdentifier()){
                    vertexItemList[j]->setPen(p);
                }
            }
        }

        QTime dieTime = QTime::currentTime().addMSecs(1000);
        while( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
        }
    } else {
        SimpleNode<SimpleList<Edge>> *route = possibleRoutes.head;
        bool added = false;
        while (route != nullptr and !added) {
            SimpleNode<Edge> *routeLastEdge = route->getData().getTail();
            if (stoi(routeLastEdge->getData().getDestiny().getId()) ==
                stoi(bestConnection->getData().getOrigin().getId())) {
                route->getData().addNodeAtEnd(bestConnection);

                SimpleNode<Edge> *aux = route->getData().head;
                while (aux->getData().getId() != bestConnection->getData().getId()) {
                    possibleRoute.addNodeAtEnd(aux->getData());
                    aux = aux->getNext();
                }
                possibleRoute.addNodeAtEnd(aux->getData());

                possibleRoutes.addNodeAtEnd(possibleRoute); //********AQUI*********

                QBrush b;
                b.setStyle(Qt::SolidPattern);
                b.setColor("#004040");
                QPen p;
                p.setStyle(Qt::SolidLine);

                p.setColor("#00ffff");
                for (int i = 0; i < edgeItemList.size(); ++i) {
                    edgeItemList[i]->setPen(p);
                }

                for (int i = 0; i < vertexItemList.size(); ++i) {
                    vertexItemList[i]->setBrush(b);
                    vertexItemList[i]->setPen(p);
                }

                p.setColor("#E74C3C");
                for (int i = 0; i < possibleRoute.len; ++i) {
                    for (int j = 0; j < edgeItemList.size(); ++j) {
                        if (possibleRoute.getNodeIn(i).getId() == edgeItemList[j]->getId()) {
                            edgeItemList[j]->setPen(p);
                        }
                    }
                    for (int j = 0; j < vertexItemList.size(); ++j) {
                        if (possibleRoute.getNodeIn(i).getOrigin().getId() == vertexItemList[j]->getIdentifier() or
                            possibleRoute.getNodeIn(i).getDestiny().getId() == vertexItemList[j]->getIdentifier()){
                            vertexItemList[j]->setPen(p);
                        }
                    }
                }

                QTime dieTime = QTime::currentTime().addMSecs(1000);
                while( QTime::currentTime() < dieTime )
                {
                    QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
                }

                added = true;
            }
            route = route->getNext();
        }

        if (!added) {
            possibleRoute.addNodeAtEnd(bestConnection->getData());
            possibleRoutes.addNodeAtEnd(possibleRoute);

            QBrush b;
            b.setStyle(Qt::SolidPattern);
            b.setColor("#004040");
            QPen p;
            p.setStyle(Qt::SolidLine);

            p.setColor("#00ffff");
            for (int i = 0; i < edgeItemList.size(); ++i) {
                edgeItemList[i]->setPen(p);
            }

            for (int i = 0; i < vertexItemList.size(); ++i) {
                vertexItemList[i]->setBrush(b);
                vertexItemList[i]->setPen(p);
            }

            p.setColor("#E74C3C");
            for (int i = 0; i < possibleRoute.len; ++i) {
                for (int j = 0; j < edgeItemList.size(); ++j) {
                    if (possibleRoute.getNodeIn(i).getId() == edgeItemList[j]->getId()) {
                        edgeItemList[j]->setPen(p);
                    }
                }
                for (int j = 0; j < vertexItemList.size(); ++j) {
                    if (possibleRoute.getNodeIn(i).getOrigin().getId() == vertexItemList[j]->getIdentifier() or
                        possibleRoute.getNodeIn(i).getDestiny().getId() == vertexItemList[j]->getIdentifier()){
                        vertexItemList[j]->setPen(p);
                    }
                }
            }

            QTime dieTime = QTime::currentTime().addMSecs(1000);
            while( QTime::currentTime() < dieTime )
            {
                QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
            }
        }
    }

    sortedActiveEdges.deleteFirstNode();

    // Gets how many connections movingToNode node have.
    SimpleNode<Edge> *checker = sortedEdges.head;
    int connections = 0;
    while (checker != nullptr) {
        if (stoi(checker->getData().getOrigin().getId()) == movingToNode or
            stoi(checker->getData().getDestiny().getId()) == movingToNode) {
            connections++;
        }
        checker = checker->getNext();
    }

    // Adds n times the route copied into "possibles routes" list.
    for (int i = 0; i < connections; i++) {
        this->possibleRoutes.addNodeAtEnd(possibleRoute);
    }

    // Calls itself recursively with a new OriginId parameter.
    calculateBestRouteRecursive(movingToNode, destinyId, vertexItemList, edgeItemList);

}

void Graph::printFinalRoute() {
    cout << endl << "*****************************************************************************************" << endl;
    cout << endl << "Final route list:" << endl;

    SimpleNode<Edge> *fEdgeAux = this->finalRoute.head;
    finalGasCapacity = fEdgeAux->getData().getWeight();
    while (fEdgeAux != nullptr) {
        cout << "Edge data - ID: " << fEdgeAux->getData().getId() << ", origin: "
             << fEdgeAux->getData().getOrigin().getId() << ", destiny: " << fEdgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(fEdgeAux->getData().getWeight()) << "." << endl;
        fEdgeAux = fEdgeAux->getNext();
    }

    cout << endl << "More expensive connection weight: " << finalGasCapacity << endl;

    cout << endl << "*****************************************************************************************" << endl;


}

void Graph::printGraph() {
    cout << endl << "Graph:" << endl << endl;
    cout << "Vertex list:" << endl;
    SimpleNode<Vertex> *vertexAux = this->vertexList.head;
    while (vertexAux != nullptr) {
        cout << "Vertex data - ID: " << vertexAux->getData().getId() << ", name: " << vertexAux->getData().getName()
             << "." << endl;
        vertexAux = vertexAux->getNext();
    }

    cout << endl << "Edges list:" << endl;
    SimpleNode<Edge> *edgeAux = this->edgesList.head;
    while (edgeAux != nullptr) {
        cout << "Edge data - ID: " << edgeAux->getData().getId() << ", connection between: "
             << edgeAux->getData().getOrigin().getId() << " and " << edgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(edgeAux->getData().getWeight()) << "." << endl;
        edgeAux = edgeAux->getNext();
    }

//    cout << endl << "Sorted edges list:" << endl;
//    SimpleNode<Edge> *sEdgeAux = this->sortedEdges.head;
//    while (sEdgeAux != nullptr) {
//        cout << "Edge data - ID: " << sEdgeAux->getData().getId() << ", origin: "
//             << sEdgeAux->getData().getOrigin().getId() << ", destiny: " << sEdgeAux->getData().getDestiny().getId()
//             << ", weight: " << to_string(sEdgeAux->getData().getWeight()) << "." << endl;
//        sEdgeAux = sEdgeAux->getNext();
//    }
}

int Graph::getFinalGasCapacity() const {
    return finalGasCapacity;
}

void Graph::setFinalGasCapacity(int finalGasCapacity) {
    Graph::finalGasCapacity = finalGasCapacity;
}
