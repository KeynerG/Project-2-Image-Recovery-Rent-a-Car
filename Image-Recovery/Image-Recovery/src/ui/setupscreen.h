#ifndef IMAGE_RECOVERY_SETUPSCREEN_H
#define IMAGE_RECOVERY_SETUPSCREEN_H

#include "loadscreen.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SetupScreen; }
QT_END_NAMESPACE

class SetupScreen : public QWidget {
Q_OBJECT

public:
    SetupScreen(QWidget *parent = nullptr);

    ~SetupScreen();

private slots:

    void on_nextButton_clicked();

private:
    Ui::SetupScreen *ui;
    LoadScreen loadScreen;
};

#endif // IMAGE_RECOVERY_SETUPSCREEN_H
