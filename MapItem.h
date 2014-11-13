// This Widget is use Marble framework under the LGPL license
//
#include <QApplication>
#include <QtQuick/QQuickView>
#include <marble/MarbleQuickItem.h>
#include <marble/MarbleMap.h>
#include <QQuickItem>
using namespace Marble;

class MapItem : public MarbleQuickItem
{
    Q_OBJECT
public:
	// MapItem();
MapItem(QQuickItem *parent=0) : MarbleQuickItem(parent)
{
	map()->setSize(width(), height());
    map()->setShowFrameRate(true);
    map()->setProjection(Mercator);
    map()->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
    map()->setShowAtmosphere(false);
    map()->setShowCompass(false);
    map()->setShowClouds(false);
    map()->setShowCrosshairs(false);
    map()->setShowGrid(false);
    map()->setShowOverviewMap(false);
    map()->setShowOtherPlaces(false);
    map()->setShowScaleBar(false);
    map()->setShowBackground(false);
}
    ~MapItem();

    void componentComplete();

public slots:

    void pinchStart(QPointF);
    void pinchEnd(QPointF, bool);
    void pinchUpdate(QPointF, qreal);

private:
    void makePinch(QPointF, Qt::GestureState, qreal);
};
