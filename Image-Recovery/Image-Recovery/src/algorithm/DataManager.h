#ifndef IMAGE_RECOVERY_DATAMANAGER_H
#define IMAGE_RECOVERY_DATAMANAGER_H

#include "src/data-structures/SimpleList.h"
#include "src/data-structures/SimpleNode.h"

#include <iostream>
#include <vector>

using namespace std;

class DataManager {

private:

    string imagePath;
    string xmlPath;
    bool isSolidImage;
    int generationsAmount;
    SimpleList<SimpleList<SimpleNode<int>>> generationsList;
    vector<int> voidSpace;
    static DataManager *instance;

protected:

    DataManager();

public:

    const string &getImagePath() const;

    void setImagePath(const string &imagePath);

    const string &getXmlPath() const;

    void setXmlPath(const string &xmlPath);

    bool isSolidImage1() const;

    void setIsSolidImage(bool isSolidImage);

    int getGenerationsAmount() const;

    void setGenerationsAmount(int generationsAmount);

    const SimpleList<SimpleList<SimpleNode<int>>> &

    getGenerationsList() const;

    void setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList);

    const vector<int> &getVoidSpace() const;

    void setVoidSpace(const vector<int> &voidSpace);

    DataManager(DataManager &other) = delete;

    void operator=(const DataManager &) = delete;

    static DataManager *getInstance();
};

#endif //IMAGE_RECOVERY_DATAMANAGER_H