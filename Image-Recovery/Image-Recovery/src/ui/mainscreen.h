#ifndef IMAGE_RECOVERY_MAINSCREEN_H
#define IMAGE_RECOVERY_MAINSCREEN_H

#include "setupscreen.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

class MainScreen : public QWidget {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);

    ~MainScreen();

private slots:

    void on_startButton_clicked();

private:
    Ui::MainScreen *ui;
    SetupScreen setupScreen;
};

#endif // IMAGE_RECOVERY_MAINSCREEN_H
