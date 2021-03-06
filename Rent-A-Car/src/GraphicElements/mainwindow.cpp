#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    //Setting initial window configurations
    setWindowTitle("Rent a Car");
    setFixedSize(400, 400);
    setStyleSheet("background-color:#001010");

    //Title
    title = new QLabel("Rent A Car", this);
    title->setAlignment(Qt::AlignCenter);
    title->setGeometry(50, 25, 300, 50);
    title->setStyleSheet("font:40px; font:bold; color:#00ffff;");

    //Instructions label
    instructionsLabel = new QLabel("Select the number of cities:", this);
    instructionsLabel->setAlignment(Qt::AlignCenter);
    instructionsLabel->setGeometry(100, 125, 200, 25);
    instructionsLabel->setStyleSheet("font-size:12; color:'white';");

    //Slider for vertex selection
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(4, 20);
    slider->setSliderPosition(4);
    slider->setGeometry(135, 155, 105, 25);
    slider->setStyleSheet("QSlider::groove-horizontal{background-color:#004040; color:#00ffff;}\n"
                          "QSlider::handle:horizontal { background-color: #004040; border: 1px solid #00ffff; width: 8px; height: 10px; line-height: 10px; margin-top: -5px; margin-bottom: -5px; border-radius: 5px;}"
                          "QSlider::sub-page:horizontal{background-color:#004040; color:#00ffff; border-radius:3px;}"
    );

    //Vertix amount display
    vertexAmount = new QLabel(this);
    vertexAmount->setNum(4);
    vertexAmount->setGeometry(245, 158, 20, 20);
    vertexAmount->setAlignment(Qt::AlignRight);
    vertexAmount->setStyleSheet("color:white; border-style: solid; border-radius: 1px; border-color: black;");
    connect(slider, SIGNAL(valueChanged(int)), vertexAmount, SLOT(setNum(int)));

    //Button to calculate rent price and generate the graphic
    confirmButton = new QPushButton(this);
    confirmButton->setText("Generate");
    confirmButton->setGeometry(150, 200, 100, 25);
    confirmButton->setStyleSheet("background-color:#004040; color:#00ffff; border-style: solid; border-radius: 3px;");
    confirmButton->setCheckable(true);
    connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(onConfirmButtonClicked(bool)));

    //Loading icon when loading routes
    loadingIcon = new QProgressBar(this);
    loadingIcon->setRange(0, 100);
    loadingIcon->setGeometry(100, 265, 200, 25);
    loadingIcon->setStyleSheet(
            "QProgressBar {""background-color: #001010;""color: white;""border-style: outset;""border-width: 1px;""border-color: #004040;""border-radius: 3px;""text-align: center; }""QProgressBar::chunk {""background-color: #004040;}");
    loadingIcon->setValue(0);
    loadingIcon->hide();

    //Close Button
    closeButton = new QPushButton(this);
    closeButton->setText("Cerrar");
    closeButton->setGeometry(140, 325, 120, 40);
    closeButton->setVisible(true);
    closeButton->setStyleSheet("color: white; background: #001010");
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeApp()));
}

MainWindow::~MainWindow() {
    delete this;
}

void MainWindow::onConfirmButtonClicked(bool checked) {
    if (checked) {
        this->loadingIcon->show();
        TravelAssistant::getInstance()->generateRoutes(this->slider->value(), this->loadingIcon);

        gw = new GraphWindow(this);
        gw->show();
        gw->drawGraph();
        this->hide();
    }
}

void MainWindow::closeApp() {
    this->gw->close();
    this->close();
}
