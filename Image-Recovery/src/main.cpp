#include "ui/mainscreen.h"

#include <QApplication>

/**
 * @fn int main(int argc, char *argv[])
 * @brief Creates the QApplication app, configures the QWidget MainScreen as the main screen and displays it in the window.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int QApplication::exec()
 * @author <a href="https://github.com/valeriehernandez-7">Valerie M. Hernández Fernández</a>
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv); /**< UI Main QApplication */
    MainScreen screen; /**< UI Main QWidget */
    screen.show();
    return app.exec();
}