#ifndef IMAGE_RECOVERY_MAINSCREEN_H
#define IMAGE_RECOVERY_MAINSCREEN_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

class MainScreen : public QWidget {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);

    ~MainScreen();

    void checkUserInformation();

private slots:

    void on_startButton_clicked();

    void on_displayLoadScreenButton_clicked();

    void on_displayGenerationScreenButton_clicked();

    void on_displayFinalScreenButton_clicked();

    void on_closeButton_clicked();

    void on_browseButton_clicked();

    void on_solidButton_clicked();

    void on_patternButton_clicked();

private:
    Ui::MainScreen *ui;
    QMessageBox *qMessageBox;
};

#endif // IMAGE_RECOVERY_MAINSCREEN_H