#include <QApplication>
#include "app/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setStyle("Fusion");

    QFile stylesheet(":style.css");

    MainWindow window;
    window.show();

    return app.exec();
}