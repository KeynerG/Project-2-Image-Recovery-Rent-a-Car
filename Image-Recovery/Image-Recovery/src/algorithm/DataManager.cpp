#include "DataManager.h"

const string &DataManager::getImagePath() const {
    return imagePath;
}

void DataManager::setImagePath(const string &imagePath) {
    DataManager::imagePath = imagePath;
}

const string &DataManager::getXmlPath() const {
    return xmlPath;
}

void DataManager::setXmlPath(const string &xmlPath) {
    DataManager::xmlPath = xmlPath;
}

bool DataManager::isSolidImage1() const {
    return isSolidImage;
}

void DataManager::setIsSolidImage(bool isSolidImage) {
    DataManager::isSolidImage = isSolidImage;
}

int DataManager::getGenerationsAmount() const {
    return generationsAmount;
}

void DataManager::setGenerationsAmount(int generationsAmount) {
    DataManager::generationsAmount = generationsAmount;
}

const SimpleList <SimpleList<SimpleNode <int>>> &

DataManager::getGenerationsList() const {
    return generationsList;
}

void DataManager::setGenerationsList(const SimpleList <SimpleList<SimpleNode <int>>> &generationsList) {
DataManager::generationsList = generationsList;
}

const vector<int> &DataManager::getVoidSpace() const {
    return voidSpace;
}

void DataManager::setVoidSpace(const vector<int> &voidSpace) {
    DataManager::voidSpace = voidSpace;
}