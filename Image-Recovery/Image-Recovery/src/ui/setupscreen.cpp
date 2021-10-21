#include "setupscreen.h"
#include "./ui_setupscreen.h"

SetupScreen::SetupScreen(QWidget *parent) : QWidget(parent), ui(new Ui::SetupScreen) {
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &loadScreen);
}

SetupScreen::~SetupScreen() {
    delete ui;
}

void SetupScreen::on_nextButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}