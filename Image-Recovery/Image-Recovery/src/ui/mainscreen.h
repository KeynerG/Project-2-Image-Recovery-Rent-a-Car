#ifndef IMAGE_RECOVERY_MAINSCREEN_H
#define IMAGE_RECOVERY_MAINSCREEN_H

#include "src/algorithm/datamanager.h"

#include <QDesktopServices>
#include <QDir>
#include <QFileDialog>
#include <QImage>
#include <QMap>
#include <QMessageBox>
#include <QPoint>
#include <QRgb>
#include <QString>
#include <QVector>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

/**
 * @class MainScreen
 * @brief
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
class MainScreen : public QWidget {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr); /**< MainScreen class constructor. */

    ~MainScreen(); /**< MainScreen class destructor. */

    /**
     * @fn void checkUserInformation()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void checkUserInformation();

    /**
     * @fn void saveGenImage(QImage image)
     * @brief
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveGenImage(QImage image);

    /**
     * @fn void imageProcessing(QPoint topLeftCorner, QPoint bottomRightCorner)
     * @brief
     * @param topLeftCorner
     * @param bottomRightCorner
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void imageProcessing(QPoint topLeftCorner, QPoint bottomRightCorner);

private slots:

    /**
     * @fn void on_startButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_startButton_clicked();

    /**
     * @fn void on_displaySetupScreenButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displaySetupScreenButton_clicked();

    /**
     * @fn void on_displayCropScreenButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayCropScreenButton_clicked();

    /**
     * @fn void on_displayCropScreenBackButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayCropScreenBackButton_clicked();

    /**
     * @fn void on_displayPreviewScreenButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayPreviewScreenButton_clicked();

    /**
     * @fn void on_displayLoadScreenButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayLoadScreenButton_clicked();

    /**
     * @fn void on_displayGenerationScreenButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayGenerationScreenButton_clicked();

    /**
     * @fn void on_displayFinalScreenButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayFinalScreenButton_clicked();

    /**
     * @fn void on_closeButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_closeButton_clicked();

    /**
     * @fn void on_browseButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_browseButton_clicked();

    /**
     * @fn void on_solidButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_solidButton_clicked();

    /**
     * @fn void on_patternButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_patternButton_clicked();

    /**
     * @fn void on_topHorizontalSlider_valueChanged(int value)
     * @brief
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_topHorizontalSlider_valueChanged(int value);

    /**
     * @fn void on_topVerticalSlider_valueChanged(int value)
     * @brief
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_topVerticalSlider_valueChanged(int value);

    /**
     * @fn void on_bottomHorizontalSlider_valueChanged(int value)
     * @brief
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_bottomHorizontalSlider_valueChanged(int value);

    /**
     * @fn void on_bottomVerticalSlider_valueChanged(int value)
     * @brief
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_bottomVerticalSlider_valueChanged(int value);

    /**
     * @fn void on_imageProgressBar_valueChanged(int value)
     * @brief
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_imageProgressBar_valueChanged(int value);

    /**
     * @fn void on_progressBar_valueChanged(int value)
     * @brief
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_progressBar_valueChanged(int value);

    /**
     * @fn void on_openButton_clicked()
     * @brief
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_openButton_clicked();

private:
    Ui::MainScreen *ui; /**<  */
    QMessageBox *qMessageBox; /**<  */
    QString userImagePath; /**<  */
    QImage *userImage; /**<  */
    QPoint topLeft; /**<  */
    QPoint bottomRight; /**<  */
    QVector<QRgb> geneticReference; /**<  */
    QList<QRgb> colorPalette; /**<  */
};

#endif // IMAGE_RECOVERY_MAINSCREEN_H