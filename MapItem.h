// This Widget is use Marble framework under the LGPL license 

#include <QApplication>
#include <QtQuick/QQuickView>
#include <marble/MarbleQuickItem.h>
#include <marble/MarbleMap.h>

using namespace Marble;

class MapItem : public MarbleQuickItem
{
    Q_OBJECT
public:
    MapItem(QQuickItem *parent=0);
    ~MapItem();

    void componentComplete();

public slots:

    void pinchStart(QPointF);
    void pinchEnd(QPointF, bool);
    void pinchUpdate(QPointF, qreal);

private:
    void makePinch(QPointF, Qt::GestureState, qreal);
    
    
};