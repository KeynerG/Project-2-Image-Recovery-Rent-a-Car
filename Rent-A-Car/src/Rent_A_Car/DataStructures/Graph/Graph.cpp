#include "Graph.h"

Graph::Graph() {
    this->edgesList = SimpleList<Edge>();
    this->vertexList = SimpleList<Vertex>();
    this->sortedEdges = SimpleList<Edge>();
    this->activeEdges = SimpleList<Edge>();
    this->finalRoutes = SimpleList<SimpleList<Edge>>();

    this->finalRoutes.setHead(nullptr);
    this->finalRoutes.setTail(nullptr);
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
    return finalRoutes;
}

void Graph::setFinalRoutes(const SimpleList<SimpleList<Edge>> &finalRoutes) {
    Graph::finalRoutes = finalRoutes;
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

    sortEdgesListByWeight();

    printGraph();

    cout << "OrigenID: ";
    int origen, destino;
    cin >> origen;
    cout << endl << endl << "DestinoID: ";
    cin >> destino;

    calculateBestRoute(origen, destino);
}

void Graph::calculateBestRoute(int originId, int destinyId) {
    if (originId == destinyId) {
        SimpleNode<SimpleList<Edge>> *aux = this->finalRoutes.getHead();

        while(aux != nullptr){
            if(stoi(aux->getData().getTail()->getData().getDestiny().getId()) == destinyId){
                SimpleNode<Edge> *auxaux = aux->getData().getHead();
                while(auxaux != nullptr){
                    this->finalRoute.addNodeAtEnd(auxaux->getData());
                    auxaux = auxaux->getNext();
                }
            }else{
                aux = aux->getNext();
            }
        }
        return;
    } else {
        int possibilities = -1;
        SimpleNode<Edge> *aux = this->sortedEdges.getHead();
        while (aux != nullptr) {
            if (stoi(aux->getData().getOrigin().getId()) == originId or
                stoi(aux->getData().getDestiny().getId()) == originId) {
                this->activeEdges.addNodeAtEnd(aux->getData());
                this->sortedEdges.deleteNode(aux);
                possibilities++;
            }
            aux = aux->getNext();
        }

        SimpleNode<Edge> *bestRoute = activeEdges.head;
        aux = activeEdges.head->getNext();
        while (aux != nullptr) {
            if (aux->getData().getWeight() <= bestRoute->getData().getWeight()) {
                bestRoute = aux;
            }
            aux = aux->getNext();
        }

        if (finalRoutes.getHead() == nullptr) {
            SimpleList<Edge> newRoute;
            newRoute.addNodeAtEnd(bestRoute->getData());
            finalRoutes.addNodeAtEnd(newRoute);
            this->activeEdges.deleteNode(bestRoute);
        } else {
            bool included = false;
            SimpleNode<SimpleList<Edge>> *aux = this->finalRoutes.getHead();
            while (aux != nullptr) {
                if (stoi(aux->getData().getTail()->getData().getDestiny().getId()) == originId) {
                    aux->getData().addNodeAtEnd(bestRoute->getData());
                    this->activeEdges.deleteNode(bestRoute);
                    included = true;
                }
                aux = aux->getNext();
            }

            if(!included){
                SimpleList<Edge> newRoute;
                newRoute.addNodeAtEnd(bestRoute->getData());
                finalRoutes.addNodeAtEnd(newRoute);
                this->activeEdges.deleteNode(bestRoute);
            }
        }

        SimpleNode<SimpleList<Edge>> *insertedElement = this->finalRoutes.getHead();
        SimpleList<Edge> listToRepeat;

        while(insertedElement != nullptr){
            if(insertedElement->getData().getTail() == bestRoute){
                listToRepeat = insertedElement->getData();
            }else{
                insertedElement = insertedElement->getNext();
            }
        }

        while(possibilities > 0){
            this->finalRoutes.addNodeAtEnd(listToRepeat);
            possibilities--;
        }

        calculateBestRoute(stoi(bestRoute->getData().getDestiny().getId()), destinyId);
    }
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
        cout << "Edge data - ID: " << edgeAux->getData().getId() << ", origin: "
             << edgeAux->getData().getOrigin().getId() << ", destiny: " << edgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(edgeAux->getData().getWeight()) << "." << endl;
        edgeAux = edgeAux->getNext();
    }
    cout << endl << "Sorted edges list:" << endl;
    SimpleNode<Edge> *sEdgeAux = this->sortedEdges.head;
    while (sEdgeAux != nullptr) {
        cout << "Edge data - ID: " << sEdgeAux->getData().getId() << ", origin: "
             << sEdgeAux->getData().getOrigin().getId() << ", destiny: " << sEdgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(sEdgeAux->getData().getWeight()) << "." << endl;
        sEdgeAux = sEdgeAux->getNext();
    }
    cout << endl << "Active edges list:" << endl;
    SimpleNode<Edge> *aEdgeAux = this->activeEdges.head;
    while (aEdgeAux != nullptr) {
        cout << "Edge data - ID: " << aEdgeAux->getData().getId() << ", origin: "
             << aEdgeAux->getData().getOrigin().getId() << ", destiny: " << aEdgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(aEdgeAux->getData().getWeight()) << "." << endl;
        aEdgeAux = aEdgeAux->getNext();
    }
    cout << endl << "Final route list:" << endl;
    SimpleNode<Edge> *fEdgeAux = this->finalRoute.head;
    while (fEdgeAux != nullptr) {
        cout << "Edge data - ID: " << fEdgeAux->getData().getId() << ", origin: "
             << fEdgeAux->getData().getOrigin().getId() << ", destiny: " << fEdgeAux->getData().getDestiny().getId()
             << ", weight: " << to_string(fEdgeAux->getData().getWeight()) << "." << endl;
        fEdgeAux = fEdgeAux->getNext();
    }
}
