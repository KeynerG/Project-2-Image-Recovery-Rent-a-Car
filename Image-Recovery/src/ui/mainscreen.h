#ifndef IMAGE_RECOVERY_MAINSCREEN_H
#define IMAGE_RECOVERY_MAINSCREEN_H

#include "src/algorithm/datamanager.h"
#include "src/algorithm/genetic.h"

#include <QDesktopServices>
#include <QDir>
#include <QFileDialog>
#include <QImage>
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
 * @brief This is the class in charge of the GUI for the program.
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
class MainScreen : public QWidget {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr); /**< MainScreen class constructor. */

    ~MainScreen(); /**< MainScreen class destructor. */

    /**
     * @fn void checkUserInformation()
     * @brief This method check if some elements of the ui are complete to habilitate the next button.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void checkUserInformation();

    /**
     * @fn void saveGenImage(QImage image)
     * @brief This method receives a QImage and saves it in the path in the variable userImage.
     * @param image
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void saveGenImage(QImage image);

    /**
     * @fn void imageProcessing(QPoint topLeftCorner, QPoint bottomRightCorner)
     * @brief This method receives two points in the image and saves all the pixel's color between this points in a QVector, then change all the colors saved to transparent.
     * @param topLeftCorner
     * @param bottomRightCorner
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void imageProcessing(QPoint topLeftCorner, QPoint bottomRightCorner);

    /**
     * @fn void sendData()
     * @brief This function saves information on the datamanager instance.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void sendData();

private slots:

    /**
     * @fn void on_startButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_startButton_clicked();

    /**
     * @fn void on_displaySetupScreenButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displaySetupScreenButton_clicked();

    /**
     * @fn void on_displayCropScreenButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayCropScreenButton_clicked();

    /**
     * @fn void on_displayCropScreenBackButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayCropScreenBackButton_clicked();

    /**
     * @fn void on_displayPreviewScreenButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayPreviewScreenButton_clicked();

    /**
     * @fn void on_displayLoadScreenButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayLoadScreenButton_clicked();

    /**
     * @fn void on_displayGenerationScreenButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayGenerationScreenButton_clicked();

    /**
     * @fn void on_displayFinalScreenButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_displayFinalScreenButton_clicked();

    /**
     * @fn void on_closeButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_closeButton_clicked();

    /**
     * @fn void on_browseButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_browseButton_clicked();

    /**
     * @fn void on_solidButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_solidButton_clicked();

    /**
     * @fn void on_patternButton_clicked()
     * @brief Function of a button clicked.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_patternButton_clicked();

    /**
     * @fn void on_topHorizontalSlider_valueChanged(int value)
     * @brief This method update the values of the topLeft variable.
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_topHorizontalSlider_valueChanged(int value);

    /**
     * @fn void on_topVerticalSlider_valueChanged(int value)
     * @brief This method update the values of the topLeft variable.
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_topVerticalSlider_valueChanged(int value);

    /**
     * @fn void on_bottomHorizontalSlider_valueChanged(int value)
     * @brief This method update the values of the bottomRight variable.
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_bottomHorizontalSlider_valueChanged(int value);

    /**
     * @fn void on_bottomVerticalSlider_valueChanged(int value)
     * @brief This method update the values of the bottomRight variable.
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_bottomVerticalSlider_valueChanged(int value);

    /**
     * @fn void on_imageProgressBar_valueChanged(int value)
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_imageProgressBar_valueChanged(int value);

    /**
     * @fn void on_progressBar_valueChanged(int value)
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_progressBar_valueChanged(int value);

    /**
     * @fn void on_generationSlider_valueChanged(int value)
     * @param value
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_generationSlider_valueChanged(int value);

    /**
     * @fn void on_openButton_clicked()
     * @brief this method opens the directory of the files generated in the program.
     * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
     */
    void on_openButton_clicked();

private:
    Genetic genetic; /**< Instance of the Genetic class. */
    Ui::MainScreen *ui; /**< Instance of the Ui. */
    QMessageBox *qMessageBox; /**< An instance of QMessageBox. */
    QString userImagePath; /**< QString that contains the path of the images generated. */
    QImage *userImage; /**< The image after make the void space. */
    QPoint topLeft; /**< QPoint that contains the coordinate of the top left pixel for the void space. */
    QPoint bottomRight; /**< QPoint that contains the coordinate of the bottom right pixel for the void space. */
    QVector<QRgb> geneticReference; /**< QVector that contains all the pixels of the void space before making it void. */
    QList<QRgb> colorPalette; /**< QList that contains the colours present in the reference. */
};

#endif // IMAGE_RECOVERY_MAINSCREEN_H