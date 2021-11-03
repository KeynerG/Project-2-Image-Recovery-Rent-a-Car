#ifndef IMAGE_RECOVERY_DATAMANAGER_H
#define IMAGE_RECOVERY_DATAMANAGER_H

#include "src/data-structures/simplelist.h"
#include "src/data-structures/simplenode.h"

#include <QMap>
#include <QString>
#include <QRect>
#include <QRgb>
#include <QVector>

/**
 * @class DataManager
 * @brief
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
class DataManager {

public:

    /**
     * @fn bool isSolidImage() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    bool isSolidImage() const;

    /**
     * @fn void setIsSolidImage(bool isSolidImage)
     * @brief
     * @param isSolidImage
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setIsSolidImage(bool isSolidImage);

    /**
     * @fn int getCurrentFileGeneration() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getCurrentFileGeneration() const;

    /**
     * @fn void setCurrentFileGeneration(int currentFileGeneration)
     * @brief
     * @param currentFileGeneration
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setCurrentFileGeneration(int currentFileGeneration);

    /**
     * @fn int getLastGenerationFile() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getLastGenerationFile() const;

    /**
     * @fn void setLastGenerationFile(int lastGenerationFile)
     * @brief
     * @param lastGenerationFile
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setLastGenerationFile(int lastGenerationFile);

    /**
     * @fn int getUserNGenerations() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getUserNGenerations() const;

    /**
     * @fn void setUserNGenerations(int userNGenerations)
     * @brief
     * @param userNGenerations
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setUserNGenerations(int userNGenerations);

    /**
     * @fn int getGenerationsAmount() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getGenerationsAmount() const;

    /**
     * @fn void setGenerationsAmount(int generationsAmount)
     * @brief
     * @param generationsAmount
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setGenerationsAmount(int generationsAmount);

    /**
     * @fn const QPoint &getFrameTopLeftPoint() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QPoint &getFrameTopLeftPoint() const;

    /**
     * @fn void setFrameTopLeftPoint(const QPoint &frameTopLeftPoint)
     * @brief
     * @param frameTopLeftPoint
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setFrameTopLeftPoint(const QPoint &frameTopLeftPoint);

    /**
     * @fn const QPoint &getFrameBottomRightPoint() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QPoint &getFrameBottomRightPoint() const;

    /**
     * @fn void setFrameBottomRightPoint(const QPoint &frameBottomRightPoint)
     * @brief
     * @param frameBottomRightPoint
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setFrameBottomRightPoint(const QPoint &frameBottomRightPoint);

    /**
     * @fn const QVector<QRgb> &getReference() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QVector<QRgb> &getReference() const;

    /**
     * @fn void setReference(const QVector<QRgb> &reference)
     * @brief
     * @param reference
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setReference(const QVector<QRgb> &reference);

    /**
     * @fn const QString &getImagePath() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QString &getImagePath() const;

    /**
     * @fn void setImagePath(const QString &imagePath)
     * @brief
     * @param imagePath
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setImagePath(const QString &imagePath);

    /**
     * @fn const QString &getGenImagePath() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QString &getGenImagePath() const;

    /**
     * @fn void setGenImagePath(const QString &genImagePath)
     * @brief
     * @param genImagePath
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setGenImagePath(const QString &genImagePath);

    /**
     * @fn const QString &getFinalImagePath() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QString &getFinalImagePath() const;

    /**
     * @fn void setFinalImagePath(const QString &finalImagePath)
     * @brief
     * @param finalImagePath
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setFinalImagePath(const QString &finalImagePath);

    /**
     * @fn const QString &getXmlPath() const
     * @brief
     * @return
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QString &getXmlPath() const;

    /**
     * @fn void setXmlPath(const QString &xmlPath)
     * @brief
     * @param xmlPath
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setXmlPath(const QString &xmlPath);

    /**
     * @fn const SimpleList<SimpleList<SimpleNode<int>>> &getGenerationsList() const
     * @brief
     * @return
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    const SimpleList<SimpleList<SimpleNode<int>>> &getGenerationsList() const;

    /**
     * @fn void setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList)
     * @brief
     * @param generationsList
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void setGenerationsList(const SimpleList<SimpleList<SimpleNode<int>>> &generationsList);

    /**
     * @fn DataManager(DataManager &other) = delete
     * @brief
     * @param other
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    DataManager(DataManager &other) = delete;

    /**
     * @fn void operator=(const DataManager &) = delete
     * @brief
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    void operator=(const DataManager &) = delete;

    /**
     * @fn static DataManager *getInstance()
     * @brief
     * @return
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    static DataManager *getInstance();

protected:
    DataManager(); /**< DataManager class constructor. */

private:
    bool solidImage; /**<  */
    int currentFileGeneration = 0; /**<  */
    int lastGenerationFile = 1; /**<  */
    int userNGenerations = 1; /**<  */
    int generationsAmount = 1; /**<  */
    QPoint frameTopLeftPoint; /**<  */
    QPoint frameBottomRightPoint; /**<  */
    QVector<QRgb> reference; /**<  */
    QString imagePath; /**<  */
    QString genImagePath = "../src/generations/" + QString(QString::fromStdString(std::to_string(getCurrentFileGeneration()))) + ".png"; /**<  */
    QString finalImagePath = "../src/generations/" + QString(QString::fromStdString(std::to_string(getLastGenerationFile()))) + ".png"; /**<  */
    QString xmlPath = "../src/generations/"; /**<  */
    SimpleList<SimpleList<SimpleNode<int>>> generationsList; /**<  */
    static DataManager *instance; /**<  */
};

#endif //IMAGE_RECOVERY_DATAMANAGER_H