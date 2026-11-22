#include <QApplication>
#include "app/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setStyle("Fusion");

    QPalette dark;
    dark.setColor(QPalette::Window, QColor("#252526"));
    dark.setColor(QPalette::WindowText, QColor("#D4D4D4"));
    dark.setColor(QPalette::Base, QColor("#1E1E1E"));
    dark.setColor(QPalette::Text, QColor("#D4D4D4"));
    dark.setColor(QPalette::Button, QColor("#2D2D30"));
    dark.setColor(QPalette::ButtonText, QColor("#D4D4D4"));
    dark.setColor(QPalette::Highlight, QColor("#3A3F5C"));
    dark.setColor(QPalette::HighlightedText, QColor("#FFFFFF"));
    app.setPalette(dark);

    MainWindow window;
    window.show();

    return app.exec();
}