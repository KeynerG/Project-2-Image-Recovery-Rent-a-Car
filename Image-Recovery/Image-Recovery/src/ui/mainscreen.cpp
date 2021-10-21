#include "mainscreen.h"
#include "./ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) : QWidget(parent), ui(new Ui::MainScreen) {
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &setupScreen);
}

MainScreen::~MainScreen() {
    delete ui;
}

void MainScreen::on_startButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}