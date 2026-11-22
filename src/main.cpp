#include <QApplication>
#include "app/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setStyle("Fusion");

    QFile stylesheet(":/style.css");
    if (stylesheet.open(QFile::ReadOnly))
        app.setStyleSheet(stylesheet.readAll());

    MainWindow window;
    window.show();

    return app.exec();
}