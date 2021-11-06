#include "datamanager.h"

DataManager *DataManager::instance = nullptr;

DataManager::DataManager() {}

bool DataManager::isSolidImage() const {
    return solidImage;
}

void DataManager::setIsSolidImage(bool solidImage) {
    DataManager::solidImage = solidImage;
}

int DataManager::getCurrentFileGeneration() const {
    return currentFileGeneration;
}

void DataManager::setCurrentFileGeneration(int currentFileGeneration) {
    DataManager::currentFileGeneration = currentFileGeneration;
}

int DataManager::getLastGenerationFile() const {
    return lastGenerationFile;
}

void DataManager::setLastGenerationFile(int lastGenerationFile) {
    DataManager::lastGenerationFile = lastGenerationFile;
}

int DataManager::getUserNGenerations() const {
    return userNGenerations;
}

void DataManager::setUserNGenerations(int userNGenerations) {
    DataManager::userNGenerations = userNGenerations;
}

int DataManager::getGenerationsAmount() const {
    return generationsAmount;
}

void DataManager::setGenerationsAmount(int generationsAmount) {
    DataManager::generationsAmount = generationsAmount;
}

const QPoint &DataManager::getFrameTopLeftPoint() const {
    return frameTopLeftPoint;
}

void DataManager::setFrameTopLeftPoint(const QPoint &frameTopLeftPoint) {
    DataManager::frameTopLeftPoint = frameTopLeftPoint;
}

const QPoint &DataManager::getFrameBottomRightPoint() const {
    return frameBottomRightPoint;
}

void DataManager::setFrameBottomRightPoint(const QPoint &frameBottomRightPoint) {
    DataManager::frameBottomRightPoint = frameBottomRightPoint;
}

const QVector<QRgb> &DataManager::getReference() const {
    return reference;
}

void DataManager::setReference(const QVector<QRgb> &reference) {
    DataManager::reference = reference;
}

const QList<QRgb> &DataManager::getColorPaletteReference() const {
    return colorPaletteReference;
}

void DataManager::setColorPaletteReference(const QList<QRgb> &colorPaletteReference) {
    DataManager::colorPaletteReference = colorPaletteReference;
}

const QString &DataManager::getFilesPath() const {
    return filesPath;
}

void DataManager::setFilesPath(const QString &filesPath) {
    DataManager::filesPath = filesPath;
}

const QString &DataManager::getImagePath() const {
    return imagePath;
}

void DataManager::setImagePath(const QString &imagePath) {
    DataManager::imagePath = imagePath;
}

DataManager *DataManager::getInstance() {
    if (instance == nullptr) {
        instance = new DataManager();
    }
    return instance;
}