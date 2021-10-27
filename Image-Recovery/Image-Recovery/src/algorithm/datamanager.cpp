#include "datamanager.h"

DataManager *DataManager::instance = nullptr;

DataManager::DataManager() {}

const QString &DataManager::getImagePath() const {
    return imagePath;
}

void DataManager::setImagePath(const QString &imagePath) {
    DataManager::imagePath = imagePath;
}

const QString &DataManager::getGenImagePath() const {
    return genImagePath;
}

void DataManager::setGenImagePath(const QString &genImagePath) {
    DataManager::genImagePath = genImagePath;
}

const QString &DataManager::getFinalImagePath() const {
    return finalImagePath;
}

void DataManager::setFinalImagePath(const QString &finalImagePath) {
    DataManager::finalImagePath = finalImagePath;
}

const QString &DataManager::getXmlPath() const {
    return xmlPath;
}

void DataManager::setXmlPath(const QString &xmlPath) {
    DataManager::xmlPath = xmlPath;
}

bool DataManager::isSolidImage() const {
    return solidImage;
}

void DataManager::setIsSolidImage(bool solidImage) {
    DataManager::solidImage = solidImage;
}

int DataManager::getCurrentGeneration() const {
    return currentGeneration;
}

void DataManager::setCurrentGeneration(int currentGeneration) {
    DataManager::currentGeneration = currentGeneration;
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

const SimpleList<SimpleList<SimpleNode<int>>> &DataManager::getGenerationsList() const {
    return generationsList;
}

void DataManager::setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList) {
    DataManager::generationsList = generationsList;
}

DataManager *DataManager::getInstance() {
    if (instance == nullptr) {
        instance = new DataManager();
    }
    return instance;
}