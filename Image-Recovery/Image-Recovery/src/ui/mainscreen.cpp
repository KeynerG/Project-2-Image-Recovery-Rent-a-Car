#include "mainscreen.h"
#include "./ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) : QWidget(parent), ui(new Ui::MainScreen) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->generationSlider, SIGNAL(valueChanged(int)), ui->genNumberLabel, SLOT(setNum(int)));
    connect(ui->topHorizontalSlider, SIGNAL(valueChanged(int)), ui->originXValueLabel, SLOT(setNum(int)));
    connect(ui->topVerticalSlider, SIGNAL(valueChanged(int)), ui->originYValueLabel, SLOT(setNum(int)));
    connect(ui->bottomHorizontalSlider, SIGNAL(valueChanged(int)), ui->finalXValueLabel, SLOT(setNum(int)));
    connect(ui->bottomVerticalSlider, SIGNAL(valueChanged(int)), ui->finalYValueLabel, SLOT(setNum(int)));
}

MainScreen::~MainScreen() {
    delete ui;
}

void MainScreen::checkUserInformation() {
    if (ui->stackedWidget->currentIndex() == 1) {
        if (QString::compare(ui->imagePathLine->text(), QString()) != 0) {
            if (ui->solidButton->isChecked() || ui->patternButton->isChecked()) {
                ui->displayCropScreenButton->setEnabled(true);
            }
        }
    }
    if (ui->stackedWidget->currentIndex() == 2) {
        if (ui->topHorizontalSlider->value() < ui->bottomHorizontalSlider->value()) {
            if (ui->topVerticalSlider->value() < ui->bottomVerticalSlider->value()) {
                ui->displayPreviewScreenButton->setEnabled(true);
            }
        } else {
            ui->displayPreviewScreenButton->setEnabled(false);
        }
    }
}

void MainScreen::removeSelection(QPoint topLeftCorner, QPoint bottomRightCorner) {
    userImage = new QImage(userImagePath);
    missingFrame = new QRect(topLeftCorner, bottomRightCorner);
    for (int y = missingFrame->topLeft().y(); y < missingFrame->bottomLeft().y(); ++y) {
        QRgb *line = reinterpret_cast<QRgb *>(userImage->scanLine(y));
        for (int x = missingFrame->topLeft().x(); x < missingFrame->topRight().x(); ++x) {
            // frameReference<>()
            // colorTable()
            QRgb &rgb = line[x];
            rgb = qRgba(qRed(0), qGreen(0), qBlue(0), qAlpha(0));
            // missingFrame<>()
        }
    }
    ui->userImageSelect->setPixmap(QPixmap::fromImage(*userImage).scaled(ui->userImageSelect->size(), Qt::AspectRatioMode::KeepAspectRatio,Qt::TransformationMode::SmoothTransformation));
}

void MainScreen::on_startButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainScreen::on_displaySetupScreenButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainScreen::on_displayCropScreenButton_clicked() {
    DataManager::getInstance()->setImagePath(ui->imagePathLine->text().toUtf8().constData());
    DataManager::getInstance()->setIsSolidImage(ui->solidButton->isChecked());
    DataManager::getInstance()->setUserNGenerations(ui->generationSpinBox->value());
    ui->stackedWidget->setCurrentIndex(2);
}

void MainScreen::on_displayCropScreenBackButton_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainScreen::on_displayPreviewScreenButton_clicked() {
    removeSelection(topLeft, bottomRight);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainScreen::on_displayLoadScreenButton_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
}

void MainScreen::on_displayGenerationScreenButton_clicked() {
    ui->generationSlider->setMaximum(DataManager::getInstance()->getGenerationsAmount());
    ui->stackedWidget->setCurrentIndex(5);
}

void MainScreen::on_displayFinalScreenButton_clicked() {
    if (ui->solidButton->isChecked()) {
        ui->formatSelectedLabel->setText("Solid");
    }
    if (ui->patternButton->isChecked()) {
        ui->formatSelectedLabel->setText("Pattern");
    }
    ui->resultImage->setPixmap(QPixmap(DataManager::getInstance()->getFinalImagePath()).scaledToWidth(ui->resultImage->width(), Qt::TransformationMode::SmoothTransformation));
    ui->filesPathLine->setText(QString(DataManager::getInstance()->getXmlPath()));
    ui->generationTotalLabel->setText(QString::fromStdString(to_string(DataManager::getInstance()->getGenerationsAmount())));
    ui->stackedWidget->setCurrentIndex(6);
}

void MainScreen::on_closeButton_clicked() {
    this->close();
}

void MainScreen::on_browseButton_clicked() {
    QString imagePath = "";
    bool validImage = false;
    imagePath = QFileDialog::getOpenFileName(this, "Image Recovery - Select your image", "../src/resources/", "Images (*.png)");
    if (QString::compare(imagePath, QString()) != 0) {
        QImage imageSelected;
        validImage = imageSelected.load(imagePath);
        if (validImage) {
            userImagePath = imagePath;
            ui->imagePathLine->setText(imagePath);
            ui->userImage->setPixmap(QPixmap::fromImage(imageSelected.scaled(ui->userImage->size(), Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation)));

            ui->userImageCrop->setPixmap(QPixmap::fromImage(imageSelected.scaled(ui->userImageCrop->size(), Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation)));
            ui->topHorizontalSlider->setValue(0);
            ui->topHorizontalSlider->setMaximum(imageSelected.width());
            ui->topVerticalSlider->setValue(0);
            ui->topVerticalSlider->setMaximum(imageSelected.height());
            ui->bottomHorizontalSlider->setValue(0);
            ui->bottomHorizontalSlider->setMaximum(imageSelected.width());
            ui->bottomVerticalSlider->setValue(0);
            ui->bottomVerticalSlider->setMaximum(imageSelected.height());
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
    ui->generationSlider->setHidden(true);
    checkUserInformation();
}

void MainScreen::on_patternButton_clicked() {
    ui->generationSpinBox->setValue(15);
    ui->generationSpinBox->setEnabled(true);
    ui->generationSlider->setHidden(false);
    checkUserInformation();
}

void MainScreen::on_topHorizontalSlider_valueChanged(int value) {
    topLeft.setX(value);
    checkUserInformation();
}

void MainScreen::on_topVerticalSlider_valueChanged(int value) {
    topLeft.setY(value);
    checkUserInformation();
}

void MainScreen::on_bottomHorizontalSlider_valueChanged(int value) {
    bottomRight.setX(value);
    checkUserInformation();
}

void MainScreen::on_bottomVerticalSlider_valueChanged(int value) {
    bottomRight.setY(value);
    checkUserInformation();
}

void MainScreen::on_openButton_clicked() {
    QString filesPath = QString(DataManager::getInstance()->getXmlPath());
    QDesktopServices::openUrl(QUrl::fromLocalFile(filesPath));
}
