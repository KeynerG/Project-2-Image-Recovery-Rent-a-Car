#ifndef IMAGE_RECOVERY_DATAMANAGER_H
#define IMAGE_RECOVERY_DATAMANAGER_H

#include <QMap>
#include <QRect>
#include <QRgb>
#include <QString>
#include <QVector>

/**
 * @class DataManager
 * @brief This class is the "data base" of the program and is a singleton.
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
class DataManager {

public:

    /**
     * @fn int getCurrentFileGeneration() const
     * @brief Getter for the currentFileGeneration variable.
     * @return int
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getCurrentFileGeneration() const;

    /**
     * @fn void setCurrentFileGeneration(int currentFileGeneration)
     * @brief Setter for the currentFileGeneration variable.
     * @param currentFileGeneration
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setCurrentFileGeneration(int currentFileGeneration);

    /**
     * @fn int getLastGenerationFile() const
     * @brief Getter for the lastGenerationFile variable.
     * @return int
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getLastGenerationFile() const;

    /**
     * @fn void setLastGenerationFile(int lastGenerationFile)
     * @brief Setter for the lastGenerationFile variable.
     * @param lastGenerationFile
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setLastGenerationFile(int lastGenerationFile);

    /**
     * @fn int getUserNGenerations() const
     * @brief Getter for the userNGenerations variable.
     * @return int
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getUserNGenerations() const;

    /**
     * @fn void setUserNGenerations(int userNGenerations)
     * @brief Setter for the userNGenerations variable.
     * @param userNGenerations
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setUserNGenerations(int userNGenerations);

    /**
     * @fn int getGenerationsAmount() const
     * @brief Getter for the generationsAmount variable.
     * @return int
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    int getGenerationsAmount() const;

    /**
     * @fn void setGenerationsAmount(int generationsAmount)
     * @brief Setter for the generationsAmount variable.
     * @param generationsAmount
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setGenerationsAmount(int generationsAmount);

    /**
     * @fn const QPoint &getFrameTopLeftPoint() const
     * @brief Getter for the frameTopLeftPoint variable.
     * @return QPoint
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QPoint &getFrameTopLeftPoint() const;

    /**
     * @fn void setFrameTopLeftPoint(const QPoint &frameTopLeftPoint)
     * @brief Setter for the frameTopLeftPoint variable.
     * @param frameTopLeftPoint
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setFrameTopLeftPoint(const QPoint &frameTopLeftPoint);

    /**
     * @fn const QPoint &getFrameBottomRightPoint() const
     * @brief Getter for the frameBottomRightPoint variable.
     * @return QPoint
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QPoint &getFrameBottomRightPoint() const;

    /**
     * @fn void setFrameBottomRightPoint(const QPoint &frameBottomRightPoint)
     * @brief Setter for the frameBottomRightPoint variable.
     * @param frameBottomRightPoint
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setFrameBottomRightPoint(const QPoint &frameBottomRightPoint);

    /**
     * @fn const QVector<QRgb> &getReference() const
     * @brief Getter for the reference variable.
     * @return QVector<QRgb>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QVector<QRgb> &getReference() const;

    /**
     * @fn void setReference(const QVector<QRgb> &reference)
     * @brief Setter for the reference variable.
     * @param reference
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setReference(const QVector<QRgb> &reference);

    /**
     * @fn const QList<QRgb> &getColorPaletteReference() const
     * @brief Getter for the colorPaletteReference variable.
     * @return QList<QRgb>
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QList<QRgb> &getColorPaletteReference() const;

    /**
     * @fn void setColorPaletteReference(const QList<QRgb> &colorPaletteReference)
     * @brief Setter for the colorPaletteReference variable.
     * @param colorPaletteReference
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setColorPaletteReference(const QList<QRgb> &colorPaletteReference);

    /**
     * @fn const QString &getFilesPath() const
     * @brief Getter for the variable.
     * @return QString
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QString &getFilesPath() const;

    /**
     * @fn void setFilesPath(const QString &filesPath)
     * @brief Setter for the filesPath variable.
     * @param filesPath
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setFilesPath(const QString &filesPath);

    /**
     * @fn const QString &getImagePath() const
     * @brief Getter for the imagePath variable.
     * @return QString
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    const QString &getImagePath() const;

    /**
     * @fn void setImagePath(const QString &imagePath)
     * @brief Setter for the imagePath variable.
     * @param imagePath
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void setImagePath(const QString &imagePath);

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
     * @brief Getter for the DataManager unique instance.
     * @return DataManager
     * @author <a href="https://github.com/KeynerG">Keyner S. Gómez Pana</a>
     */
    static DataManager *getInstance();

protected:
    DataManager(); /**< DataManager class constructor. */

private:
    int currentFileGeneration = 0; /**< Integer that count the files generated. */
    int lastGenerationFile = 1; /**< Integer */
    int userNGenerations = 1; /**< Integer */
    int generationsAmount = 0; /**< Integer that count the generations created. */
    QPoint frameTopLeftPoint; /**< QPoint that contains the coordinate of the top left pixel for the void space. */
    QPoint frameBottomRightPoint; /**< QPoint that contains the coordinate of the bottom right pixel for the void space. */
    QVector<QRgb> reference; /**< QVector that contains all the pixels of the void space before making it void. */
    QList<QRgb> colorPaletteReference; /**< QList that contains the colours present in the reference. */
    QString filesPath = "../src/generations/"; /**< QString that contains the path of the files generated. */
    QString imagePath; /**< QString that contains the path of the images generated. */
    static DataManager *instance; /**< Unique instance of DataManager. */
};

#endif //IMAGE_RECOVERY_DATAMANAGER_H