#ifndef IMAGE_RECOVERY_DATAMANAGER_H
#define IMAGE_RECOVERY_DATAMANAGER_H

#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QMap>
#include <QString>
#include <QRect>
#include <QRgb>
#include <QVector>

class DataManager {

public:

    bool isSolidImage() const;

    void setIsSolidImage(bool isSolidImage);

    int getCurrentFileGeneration() const;

    void setCurrentFileGeneration(int currentFileGeneration);

    int getLastGenerationFile() const;

    void setLastGenerationFile(int lastGenerationFile);

    int getUserNGenerations() const;

    void setUserNGenerations(int userNGenerations);

    int getGenerationsAmount() const;

    void setGenerationsAmount(int generationsAmount);

    const QRect &getFrame() const;

    void setFrame(const QRect &frame);

    const QVector<QRgb> &getReference() const;

    void setReference(const QVector<QRgb> &reference);

    const QMap<QRgb, int> &getColorTableReference() const;

    void setColorTableReference(const QMap<QRgb, int> &colorTableReference);

    const QString &getImagePath() const;

    void setImagePath(const QString &imagePath);

    const QString &getGenImagePath() const;

    void setGenImagePath(const QString &genImagePath);

    const QString &getFinalImagePath() const;

    void setFinalImagePath(const QString &finalImagePath);

    const QString &getXmlPath() const;

    void setXmlPath(const QString &xmlPath);

    const SimpleList<SimpleList<SimpleNode<int>>> &getGenerationsList() const;

    void setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList);

    DataManager(DataManager &other) = delete;

    void operator=(const DataManager &) = delete;

    static DataManager *getInstance();

protected:
    DataManager();

private:
    bool solidImage;
    int currentFileGeneration = 1;
    int lastGenerationFile = 1;
    int userNGenerations = 1;
    int generationsAmount = 1;
    QRect frame;
    QVector<QRgb> reference;
    QMap<QRgb, int> colorTableReference;
    QString imagePath;
    QString genImagePath = "../src/generations/" + QString(QString::fromStdString(std::to_string(getCurrentFileGeneration()))) + ".png";
    QString finalImagePath = "../src/generations/" + QString(QString::fromStdString(std::to_string(getLastGenerationFile()))) + ".png";
    QString xmlPath = "../src/generations/";
    SimpleList<SimpleList<SimpleNode<int>>> generationsList;
    static DataManager *instance;
};

#endif //IMAGE_RECOVERY_DATAMANAGER_H