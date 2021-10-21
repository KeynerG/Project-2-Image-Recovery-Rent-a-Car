#include "geneticscreen.h"
#include "./ui_geneticscreen.h"

GeneticScreen::GeneticScreen(QWidget *parent) : QWidget(parent), ui(new Ui::GeneticScreen) {
    ui->setupUi(this);
}

GeneticScreen::~GeneticScreen() {
    delete ui;
}

void GeneticScreen::on_nextButton_clicked() {

}
