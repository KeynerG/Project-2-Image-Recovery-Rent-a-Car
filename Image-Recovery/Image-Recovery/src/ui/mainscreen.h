#ifndef IMAGE_RECOVERY_MAINSCREEN_H
#define IMAGE_RECOVERY_MAINSCREEN_H

#include "src/algorithm/DataManager.h"

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

class MainScreen : public QWidget {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);

    ~MainScreen();

    void checkUserInformation();

    void removeSelection(QPoint topLeftCorner, QPoint bottomRightCorner);

private slots:

    void on_startButton_clicked();

    void on_displaySetupScreenButton_clicked();

    void on_displayCropScreenButton_clicked();

    void on_displayCropScreenBackButton_clicked();

    void on_displayPreviewScreenButton_clicked();

    void on_displayLoadScreenButton_clicked();

    void on_displayGenerationScreenButton_clicked();

    void on_displayFinalScreenButton_clicked();

    void on_closeButton_clicked();

    void on_browseButton_clicked();

    void on_solidButton_clicked();

    void on_patternButton_clicked();

    void on_topHorizontalSlider_valueChanged(int value);

    void on_topVerticalSlider_valueChanged(int value);

    void on_bottomHorizontalSlider_valueChanged(int value);

    void on_bottomVerticalSlider_valueChanged(int value);

    void on_openButton_clicked();

private:
    Ui::MainScreen *ui;
    QMessageBox *qMessageBox;
    QString userImagePath;
    QImage *userImage;
    QPoint topLeft;
    QPoint bottomRight;
    QRect *missingFrame;
};

#endif // IMAGE_RECOVERY_MAINSCREEN_H
