#ifndef IMAGE_RECOVERY_DATAMANAGER_H
#define IMAGE_RECOVERY_DATAMANAGER_H

#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QString>

class DataManager {

public:
    const QString &getImagePath() const;

    void setImagePath(const QString &imagePath);

    const QString &getFinalImagePath() const;

    void setFinalImagePath(const QString &finalImagePath);

    const QString &getXmlPath() const;

    void setXmlPath(const QString &xmlPath);

    bool isSolidImage() const;

    void setIsSolidImage(bool isSolidImage);

    int getGenerationsAmount() const;

    void setGenerationsAmount(int generationsAmount);

    const SimpleList<SimpleList<SimpleNode<int>>> &getGenerationsList() const;

    void setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList);

    DataManager(DataManager &other) = delete;

    void operator=(const DataManager &) = delete;

    static DataManager *getInstance();

private:
    QString imagePath;
    QString finalImagePath;
    QString xmlPath = "../src/generations";
    bool solidImage;
    int generationsAmount;
    SimpleList<SimpleList<SimpleNode<int>>> generationsList;
    static DataManager *instance;

protected:
    DataManager();
};

#endif //IMAGE_RECOVERY_DATAMANAGER_H