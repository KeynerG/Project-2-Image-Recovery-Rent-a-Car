#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainScreen *ui;
};
#endif // MAINSCREEN_H
