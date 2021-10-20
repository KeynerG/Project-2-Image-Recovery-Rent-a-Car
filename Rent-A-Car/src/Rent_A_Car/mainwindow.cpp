#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    //Setting initial window configurations
    setWindowTitle("Rent a Car");
    setFixedSize(400,300);
    setStyleSheet("background-color:#001010");

    //Title
    title = new QLabel("Rent A Car",this);
    title->setAlignment(Qt::AlignCenter);
    title->setGeometry(50,75,300,50);
    title->setStyleSheet("font:40px; font:bold; color:#00ffff;");

    //Instructions label
    instructionsLabel = new QLabel("Select the number of cities:",this);
    instructionsLabel->setAlignment(Qt::AlignCenter);
    instructionsLabel->setGeometry(100,175,200,25);
    instructionsLabel->setStyleSheet("font-size:12; color:#00ffff;");

    //Slider for vertex selection
    slider = new QSlider(Qt::Horizontal,this);
    slider->setRange(2,20);
    slider->setSliderPosition(2);
    slider->setGeometry(135,205,105,25);
    slider->setStyleSheet("QSlider::groove-horizontal{background-color:#004040; color:00ffff;}\n"
            "QSlider::handle:horizontal { background-color: #004040; border: 1px solid #00ffff; width: 8px; height: 10px; line-height: 10px; margin-top: -5px; margin-bottom: -5px; border-radius: 5px;}"
            );

    //Vertix amount display
    vertexAmount = new QLabel(this);
    vertexAmount->setNum(2);
    vertexAmount->setGeometry(245,208,20,20);
    vertexAmount->setAlignment(Qt::AlignRight);
    vertexAmount->setStyleSheet("color:white; border-style: solid; border-radius: 1px; border-color: black;");
    connect(slider, SIGNAL(valueChanged(int)),vertexAmount, SLOT(setNum(int)));

    //Button to calculate rent price and generate the graphic
    confirmButton = new QPushButton(this);
    confirmButton->setText("Generate");
    confirmButton->setGeometry(150,250,100,25);
    confirmButton->setStyleSheet("background-color:#004040; color:#00ffff; border-style: solid; border-radius: 1px;");
    confirmButton->setCheckable(true);
    connect(confirmButton, SIGNAL(clicked(bool)),this,SLOT(onConfirmButtonClicked(bool)));
}

MainWindow::~MainWindow(){
    delete this;
}

void MainWindow::onConfirmButtonClicked(bool checked) {
    if(checked){
        Graph g;
        g.generateGraphOf(this->slider->value());
        g.printGraph();
    }
}
