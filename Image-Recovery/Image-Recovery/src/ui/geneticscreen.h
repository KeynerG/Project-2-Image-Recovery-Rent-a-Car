#ifndef IMAGE_RECOVERY_GENETICSCREEN_H
#define IMAGE_RECOVERY_GENETICSCREEN_H


#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GeneticScreen; }
QT_END_NAMESPACE

class GeneticScreen : public QWidget {
Q_OBJECT

public:
    GeneticScreen(QWidget *parent = nullptr);

    ~GeneticScreen();

private slots:

    void on_nextButton_clicked();

private:
    Ui::GeneticScreen *ui;
};

#endif // IMAGE_RECOVERY_GENETICSCREEN_H
