#include "GraphicElements/Graph/GraphWindow.h"

GraphWindow::GraphWindow(QWidget *parent) {
    setFixedSize(610, 610);
    setBackgroundBrush(QColor("#001010"));
    this->scene = new QGraphicsScene(0, 0, 600, 500, this);
    setScene(this->scene);
    setWindowTitle("Rent A Car");
}

void GraphWindow::drawGraph() {
    SimpleList<Vertex> vertexList = travelAssistant->getRoutes().getVertexList();
    for (int i = 0; i < vertexList.len; i++) {
        complex<double> pos = calculateNodePosition(i, vertexList.len);
        positions.addNodeAtEnd(pos);
        labelList.append(QString::fromStdString(vertexList.getNodeIn(i).getId()));
    }
    this->drawEdges(travelAssistant->getRoutes().getEdgesList());
    this->drawNodes(vertexList);
    this->drawButtons(labelList);
}

void GraphWindow::drawNodes(SimpleList<Vertex> routeList) {
    for (int i = 0; i < routeList.len; i++) {
        auto *v = new VertexItem(routeList.getNodeIn(i).getId(), positions.getNodeIn(i));
        v->setParent(this->scene);
        this->scene->addItem(v);

        vertexItemList.append(v);
    }
}

void GraphWindow::drawEdges(SimpleList<Edge> edgeList) {
    for (int i = 0; i < edgeList.len; i++) {
        string originID = edgeList.getNodeIn(i).getOrigin().getId();
        string destinyID = edgeList.getNodeIn(i).getDestiny().getId();
        int w = edgeList.getNodeIn(i).getWeight();
        complex<double> oriPos = positions.getNodeIn(stoi(originID) - 1);
        complex<double> desPos = positions.getNodeIn(stoi(destinyID) - 1);
        auto *e = new EdgeItem(oriPos, desPos, edgeList.getNodeIn(i).getId(), w);
        e->setParent(this->scene);
        this->scene->addItem(e);

        edgeItemList.append(e);
    }
}

complex<double> GraphWindow::calculateNodePosition(int k, int n) {
    auto *z = new complex<int>(10, 18);
    double rn = sqrt(pow(z->real(), 2) + pow(z->imag(), 2));
    double narg = qDegreesToRadians(arg(*z)) / n;
    double npi = (2 * M_PI) / n;
    auto *res = new complex<double>((8 * rn * cos(narg + k * npi)) + 290, (8 * rn * sin(narg + k * npi)) + 180);
    return *res;
}

void GraphWindow::drawButtons(QStringList labelList) {

    //Origin Selection
    originLabel = new QLabel(this);
    originLabel->setText("Ciudad Origen:");
    originLabel->setStyleSheet("color: white; background: #001010");
    originLabel->setAlignment(Qt::AlignCenter);
    originLabel->setGeometry(100, 500, 100, 35);
    originLabel->setVisible(true);

    originBox = new QComboBox(this);
    originBox->addItems(labelList);
    originBox->setGeometry(210, 500, 50, 35);
    originBox->setVisible(true);
    originBox->setStyleSheet("color: white; background: #001010");

    //Destiny selection
    destinyLabel = new QLabel(this);
    destinyLabel->setText("Ciudad Destino:");
    destinyLabel->setStyleSheet("color: white; background: #001010");
    destinyLabel->setAlignment(Qt::AlignCenter);
    destinyLabel->setGeometry(340, 500, 110, 35);
    destinyLabel->setVisible(true);

    destinyBox = new QComboBox(this);
    destinyBox->addItems(labelList);
    destinyBox->setGeometry(460, 500, 50, 35);
    destinyBox->setVisible(true);
    destinyBox->setStyleSheet("color: white; background: #001010;");


    //Start Button
    startButton = new QPushButton(this);
    startButton->setText("Calcular Precio");
    startButton->setGeometry(245, 550, 120, 50);
    startButton->setVisible(true);
    startButton->setStyleSheet("color: white; background: #001010");
    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(start()));
}

void GraphWindow::start() {
    int originID = originBox->currentText().toInt();
    int destinyID = destinyBox->currentText().toInt();
    if (originID == destinyID) {
        QMessageBox::warning(this, tr("Origen o destino invalidos"),
                             tr("Por favor, digite un origen y un destino diferentes."));
    } else {
        startButton->setEnabled(false);
        originBox->setEnabled(false);
        destinyBox->setEnabled(false);
        travelAssistant->calculateRoute(originID, destinyID, vertexItemList, edgeItemList);
        QMessageBox::information(this, QString("¡Ruta encontrada!"), QString("La capacidad de tanque requerida es de " +
                                                                             QString::fromStdString(to_string(
                                                                                     travelAssistant->getRoutes().getFinalGasCapacity())) +
                                                                             " litros."));
        startButton->setEnabled(true);
        originBox->setEnabled(true);
        destinyBox->setEnabled(true);
    }
}