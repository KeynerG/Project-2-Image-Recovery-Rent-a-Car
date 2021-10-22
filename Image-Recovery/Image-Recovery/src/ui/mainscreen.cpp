#include "mainscreen.h"
#include "./ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) : QWidget(parent), ui(new Ui::MainScreen) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainScreen::~MainScreen() {
    delete ui;
}

void MainScreen::on_startButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainScreen::on_displayLoadScreenButton_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainScreen::on_displayGenerationScreenButton_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
}

void MainScreen::on_displayFinalScreenButton_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
}

void MainScreen::on_closeButton_clicked() {
    this->close();
}

void MainScreen::on_browseButton_clicked() {
    QString imagePath = "";
    bool validImage = false;
    imagePath = QFileDialog::getOpenFileName(this, "Image Recovery - Select your image", "", "Images (*.jpg, *.jpeg, *.png)");
    if (QString::compare(imagePath, QString()) != 0) {
        QImage imageSelected;
        validImage = imageSelected.load(imagePath);
        if (validImage) {
            ui->imagePathLine->setText(imagePath);
            imageSelected = imageSelected.scaledToWidth(ui->userImage->width(),
                                                        Qt::TransformationMode::SmoothTransformation);
            ui->userImage->setPixmap(QPixmap::fromImage(imageSelected));
        } else {
            qMessageBox = new QMessageBox(QMessageBox::Warning, "Image Recovery - Alert", "The selected file is not a valid image file.", QMessageBox::StandardButton::Ok, this);
            qMessageBox->exec();
        }
        checkUserInformation();
    }
}

void MainScreen::on_solidButton_clicked() {
    ui->generationSpinBox->setValue(1);
    ui->generationSpinBox->setEnabled(false);
    checkUserInformation();
    DataManager::getInstance()->setGenerationsAmount(ui->generationSpinBox->value());
}

void MainScreen::on_patternButton_clicked() {
    ui->generationSpinBox->setValue(15);
    ui->generationSpinBox->setEnabled(true);
    checkUserInformation();
    DataManager::getInstance()->setGenerationsAmount(ui->generationSpinBox->value());
}

void MainScreen::checkUserInformation() {
    if (QString::compare(ui->imagePathLine->text(), QString()) != 0) {
        if (ui->solidButton->isChecked() || ui->patternButton->isChecked()) {
            ui->displayLoadScreenButton->setEnabled(true);
        }
    }
}