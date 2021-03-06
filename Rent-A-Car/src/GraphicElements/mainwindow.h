#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QProgressBar>

#include "src/DataStructures/Graph/Graph.h"
#include "src/LogicManagment/TravelAssistant.h"
#include "src/GraphicElements/Graph/GraphWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void onConfirmButtonClicked(bool checked);

    void closeApp();

private:
    Ui::MainWindow *ui;
    QLabel *title;
    QLabel *instructionsLabel;
    QSlider *slider;
    QLabel *vertexAmount;
    QPushButton *confirmButton;
    QPushButton *closeButton;
    QProgressBar *loadingIcon;
    GraphWindow *gw;
};

#endif // MAINWINDOW_H
