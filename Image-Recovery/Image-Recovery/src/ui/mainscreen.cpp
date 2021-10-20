#include "mainscreen.h"
#include "./ui_mainscreen.h"
#include <iostream>

MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScreen)
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}


void MainScreen::on_pushButton_clicked()
{
    std::cout << "StartButton" << std::endl;
}

