#ifndef IMAGE_RECOVERY_LOADSCREEN_H
#define IMAGE_RECOVERY_LOADSCREEN_H

#include "geneticscreen.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoadScreen; }
QT_END_NAMESPACE

class LoadScreen : public QWidget {
Q_OBJECT

public:
    LoadScreen(QWidget *parent = nullptr);

    ~LoadScreen();

private slots:

    void on_nextButton_clicked();

private:
    Ui::LoadScreen *ui;
    GeneticScreen geneticScreen;
};

#endif // IMAGE_RECOVERY_LOADSCREEN_H
