#ifndef IMAGE_RECOVERY_DATAMANAGER_H
#define IMAGE_RECOVERY_DATAMANAGER_H

#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QString>

class DataManager {

public:

    const QString &getImagePath() const;

    void setImagePath(const QString &imagePath);

    const QString &getGenImagePath() const;

    void setGenImagePath(const QString &genImagePath);

    const QString &getFinalImagePath() const;

    void setFinalImagePath(const QString &finalImagePath);

    const QString &getXmlPath() const;

    void setXmlPath(const QString &xmlPath);

    bool isSolidImage() const;

    void setIsSolidImage(bool isSolidImage);

    int getCurrentGeneration() const;

    void setCurrentGeneration(int currentGeneration);

    int getUserNGenerations() const;

    void setUserNGenerations(int userNGenerations);

    int getGenerationsAmount() const;

    void setGenerationsAmount(int generationsAmount);

    const SimpleList<SimpleList<SimpleNode<int>>> &getGenerationsList() const;

    void setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList);

    DataManager(DataManager &other) = delete;

    void operator=(const DataManager &) = delete;

    static DataManager *getInstance();

protected:
    DataManager();

private:
    bool solidImage;
    int currentGeneration = 1;
    int userNGenerations = 1;
    int generationsAmount = 1;
    QString imagePath;
    QString genImagePath = "../src/generations/" + QString(QString::fromStdString(std::to_string(getCurrentGeneration()))) + ".png";
    QString finalImagePath = "../src/generations/" + QString(QString::fromStdString(std::to_string(getGenerationsAmount()))) + ".png";
    QString xmlPath = "../src/generations/";
    SimpleList<SimpleList<SimpleNode<int>>> generationsList;
    static DataManager *instance;
};

#endif //IMAGE_RECOVERY_DATAMANAGER_H