#include "loadscreen.h"
#include "./ui_loadscreen.h"

LoadScreen::LoadScreen(QWidget *parent) : QWidget(parent), ui(new Ui::LoadScreen) {
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &geneticScreen);
}

LoadScreen::~LoadScreen() {
    delete ui;
}

void LoadScreen::on_nextButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}
