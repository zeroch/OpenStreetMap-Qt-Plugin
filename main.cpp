#include <QtGui/QApplication>
#include <marble/MarbleWidget.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    // Load Marble using OpenStreetMap in Mercator projection
    Marble::MarbleWidget *mapWidget = new Marble::MarbleWidget;
    mapWidget->setProjection(Marble::Mercator);
    mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");

    mapWidget->setWindowTitle("Hello Marble!");
    mapWidget->show();
    return app.exec();
}